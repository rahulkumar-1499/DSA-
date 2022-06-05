#include<string.h>
#include<iostream>
using namespace std;


template<typename A>

class MyMapNode
{
    public:
    string key;
    A value;
    MyMapNode *next;
    MyMapNode(string key,A value)
    {
        this->key=key;
        this->value=value;
        this->next=NULL;

    }
    ~MyMapNode()
    {
        delete next;
    }

};

template<typename A>
class mymap
{
        MyMapNode<A>** buckets;
        int count;
        int numBuckets;

        int getBucketIndex(string key)                  //hash()
        {
            int hashCode=0;
            int currentCoeff=1;
            for(int i=key.length()-1;i>=0;i--)
            {
                hashCode=key[i]*currentCoeff;           //hashcode
                hashCode=hashCode/numBuckets;
                currentCoeff*=37;
                currentCoeff=currentCoeff/numBuckets;

            }
            return hashCode/numBuckets;             //compressing code
        }
        void rehash()
        {
            MyMapNode<A>**temp=buckets;
            buckets=new MyMapNode<A>*[2*numBuckets];
            for(int i=0;i<2*numBuckets;i++)
            {
                buckets[i]=NULL;
            }
            int oldnumbuckets=numBuckets;
            numBuckets=2*numBuckets;
            count=0;
            for(int i=0;i<oldnumbuckets;i++)
            {
                MyMapNode<A>*head=temp[i];
                while(head!=NULL)
                {
                    string key=head->key;
                    A value=head->value;
                    insert(key,value);
                    head=head->next;
                }

            }
            for(int i=0;i<oldnumbuckets;i++)
            {
                MyMapNode<A>*head=temp[i];
                delete head;

            }
            delete[] temp;

        }
        public:
        mymap()
        {
            count=0;
            numBuckets=5;
            for(int i=0;i<numBuckets;i++)
            {
                buckets[i]=NULL;

            }
        }
        ~mymap()
        {
            for(int i=0;i<numBuckets;i++)
            {
                delete buckets[i];

            }
            delete[] buckets;
        }

        void insert(string key, A value)
        {
            int indexbucket=getBucketIndex(key);
            MyMapNode<A>* head=buckets[indexbucket];
            
            while(head!=NULL)
            {
                if(head->key==key)
                {
                    head->value=value;
                }
                head=head->next;
            }
            head=buckets[indexbucket];
            MyMapNode<A>*node=new MyMapNode<A>(key,value);
            node->next=head;
            buckets[indexbucket]=node;
            count++;
            double loadfactor=(1.0*count)/numBuckets;
            if(loadfactor>0.7)
            {
                rehash();
            }

        }
        int size()
        {
            return count;
        }

        A remove(string key)
        {
            int indexbucket=getBucketIndex(key);
            MyMapNode<A>* head=buckets[indexbucket];
            MyMapNode<A>*prev=NULL;
            while(head!=NULL)
            {
                if(head->key==key)
                {
                    if(prev==NULL)
                    {
                    buckets[indexbucket]=head->next;

                    }
                    else
                    {
                        prev->next=head->next;
                    }
                    A value=head->value;
                    head->next=NULL;
                    delete head;
                    count--;
                    return value;

                }
                prev=head;
                head=head->next;

            }
            return 0;

        }

        A getValue(string key)
        {
             int indexbucket=getBucketIndex(key);
            MyMapNode<A>* head=buckets[indexbucket];
            while(head!=NULL)
            {
                if(head->key==key)
                {
                    return head->value;

                }
                head=head->next;
        }
        return 0;
        }


};



