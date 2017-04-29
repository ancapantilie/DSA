#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

template<typename T> struct list_elem
{
    T info;
    struct list_elem<T> *next, *prev;
};

template <typename T> class LinkedList
{
public:
    struct list_elem<T> *pfirst, *plast;
    void addFirst(T x)
    {
        struct list_elem<T> *paux;

        paux = new struct list_elem<T>;
        paux->info = x;
        paux->prev = NULL;
        paux->next = pfirst;

        if (pfirst != NULL) pfirst->prev = paux;
        pfirst = paux;

        if (plast==NULL) plast=pfirst;
    }

    void addLast(T x)
    {
        struct list_elem<T> *paux;

        paux = new struct list_elem<T>;
        paux->info = x;
        paux->prev = plast;
        paux->next = NULL;

        if (plast != NULL) plast->next = paux;
        plast = paux;
        if (pfirst == NULL) pfirst = plast;
    }
    void removeFirst()
    {
        struct list_elem<T>* paux;

        if (pfirst != NULL)
        {
            paux = pfirst->next;
            if (pfirst == plast) plast = NULL;
            delete pfirst;
            pfirst = paux;
            if (pfirst != NULL) pfirst->prev = NULL;
        }
        else cout<<"The list is empty"<<endl;
    }

    void removeLast()
    {
        struct list_elem<T> *paux;

        if (plast != NULL)
        {
            paux = plast->prev;
            if (pfirst == plast) pfirst = NULL;
            delete plast;
            plast = paux;
            if (plast != NULL) plast->next = NULL;
        }
        else cout<<"The list is empty"<<endl;
    }
    struct list_elem<T>* findFirstOccurrence(T x)
    {
        struct list_elem<T> *paux;

        paux = pfirst;
        while (paux != NULL)
        {
            if (paux->info == x)
                return paux;
            paux = paux->next;
        }
        return NULL;
    }

    struct list_elem<T>* findLastOccurrence(T x)
    {
        struct list_elem<T> *paux;

        paux = plast;
        while (paux != NULL)
        {
            if (paux->info == x)
                return paux;
            paux = paux->prev;
        }

        return NULL;
    }
    void removeFirstOccurrence(T x)
    {
        struct list_elem<T> *px;

        px = findFirstOccurrence(x);

        if (px != NULL)
        {
            if (px->prev != NULL)
                px->prev->next = px->next;
            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // px == plast
                plast = px->prev;

            delete px;
        }
    }

    void removeLastOccurrence(T x)
    {
        struct list_elem<T> *px;

        px = findLastOccurrence(x);

        if (px != NULL)
        {
            if (px->prev != NULL)
                px->prev->next = px->next;
            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) // px == pfirst
                pfirst = px->next;

            if (px->next == NULL) // px == plast
                plast = px->prev;

            delete px;
        }
    }


    void listInsert(int x) {
        if(findFirstOccurrence(x) == NULL){
            addFirst(x);
        } else {
            cout << "Already in list" << "\n";
        }
    }

    void sortedListInsert(int x){
        struct list_elem<int> *p, *paux;
            p = pfirst;
            while (p != NULL && p->info < x)
                p = p->next;

            if (p == NULL)
                addLast(x);
            else {
                paux = new struct list_elem<int>;

                paux->info = x;
                paux->next = p;
                paux->prev = p->prev;

                if (p->prev != NULL)
                    p->prev->next = paux;
                else
                 pfirst = paux;

                p->prev = paux;
            }
    }


    int dividedByZNr (int z) {
        int result= 0;
         struct list_elem<int> *paux;
         paux = pfirst;
            while (paux != NULL) {
                if (paux->info % z == 0){
                    result++;
                }
                paux = paux->next;
            }
        return result;
    }


    int greaterThanFirstNr(){
        int result= 0;
        struct list_elem<int> *paux;
        paux = pfirst;
        while (paux != NULL){
            if(paux->info > pfirst->info){
                result++;
            }
            paux=paux->next;
        }

        return result;
    }


    int findOccurenceNr(int x){
        int result= 0;
        struct list_elem<int> *paux;
        paux = pfirst;
        while (paux != NULL){
            if(paux->info == x){
                result++;
            }
            paux=paux->next;
        }

        return result;
    }

    int isEmpty()
    {
        return (pfirst == NULL);
    }

    LinkedList()
    {
        pfirst = plast = NULL;
    }

    void printList()
    {
        struct list_elem<T> *p;

        p = pfirst;
        while (p != NULL)
        {
            cout<<p->info<<" ";
            p = p->next;
        }
    }

//the sorting algorihm used for ex2
    void sortAscending(){

    struct list_elem<T> *paux;
    paux = pfirst;

        while (paux != NULL) {
            struct list_elem<T> *paux2;
            paux2 = paux->next;

                while(paux2 != NULL){
                        if(paux2->info < paux->info ){
                            T aux= paux->info;
                            paux->info=paux2->info;
                            paux2->info=aux;

                        }


                  paux2=paux2->next;
                }

        paux=paux->next;
        }
    }


};
