#include <iostream>

using namespace std;


/*implement dynamique array */

#define min_capacity 2 
#define incrase_size 2 
template <class T>
class Dynamique_array
{
    private:
    T *tab =NULL;
    int capacity = min_capacity;
    int size =0;
    public:
    Dynamique_array();
    int get_size();
    T get_element(int pos);
    void resize();
    void insert_at(T element,int pos);
    void append(T element);
    void del_element(int pos);
    void print();
};

template <class T >
Dynamique_array<T>::Dynamique_array()
{
    T* tab=new T [capacity];
    size=0;
    
}

template<class T>
int Dynamique_array<T>::get_size()
{
    return size;
}

template<class T >
T Dynamique_array<T>::get_element(int pos)
{
    return tab[pos];
}
/* 1   3   5    6   */
template<class T>
void Dynamique_array<T>::del_element(int pos)
{
    for(int i =pos;i<size;i++)
    {
        tab[i]=tab[i+1];
    }
    size--;
    
}
//size =4 
/*  1   3   4   */
template<class T>
void Dynamique_array<T>::insert_at(T element ,int pos)
{
    if (pos == size)
    {
        resize();
    }
    for(int i =size;i>pos ;i--)
    {
        tab[i]=tab[i-1];
    }
    tab[pos]=element;
    size++;
    
}

template<class T>
void Dynamique_array<T>::append(T element)
{
    insert_at(element,size);
}

template<class T>
void Dynamique_array<T>::resize()
{
    capacity*=incrase_size;
    T* temp=new T [capacity];
    std::copy(tab, tab+size, temp);
    delete [] tab;
    tab =temp;
}

template<class T>
void Dynamique_array<T>::print()
{
    for (int i =0;i<size;i++)
    cout<<tab[i]<<endl;
}

int main()
{
    Dynamique_array<int> arr;
    arr.append(5);
    arr.append(4);
    arr.append(3);
    arr.insert_at(2,1);
    arr.insert_at(0,0);
    arr.del_element(0);
    arr.print();
    return 0;
}
