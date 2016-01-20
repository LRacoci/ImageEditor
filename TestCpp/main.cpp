#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdarg.h>
#include <stdio.h>

using namespace std;
/*
//rotate/flip a quadrant appropriately
void rot(int n, int v[], int r[]) {
    if (r[1] == 0) {
        if (r[0] == 1) {
            v[0] = n-1 - v[0];
            v[1] = n-1 - v[1];
        }

        //Swap x and y
        int t  = v[0];
        v[0] = v[1];
        v[1] = t;
    }
}
//convert (x,y) to d
int hilbert_v2d (int n, int v[]) {
    int r[], d=0;
    int s;
    for (s=n/2; s>0; s>>1) {
        r[0] = (v[0] & s) > 0;
        r[1] = (v[1] & s) > 0;
        d += s * s * ((3 * r[0]) ^ r[1]);
        rot(s, v, r);
    }
    return d;
}

//convert d to (x,y)
int *hilbert_d2v(int n, int d) {
    int v[], r[], s, t=d;
    v[0] = v[1] = 0;
    for (s=1; s<n; s<<=1) {
        r[0] = 1 & (t/2);
        r[1] = 1 & (t ^ r[0]);
        rot(s, v, r);
        v[0] += s * r[0];
        v[1] += s * r[1];
        t >>= 2;
    }
    return v;
}*/


class List{
public:
    unsigned sub_size;
  private:
    class Node{
      public:
        void ** e;
        Node *b, *a;
    } * node;
  public:
    unsigned size;
    List(unsigned sub_size_value){
        size = 0;
        sub_size = sub_size_value;
        node = new Node();
    }
    List() : List(6){};

    template <typename T>
    void operator,(T append){
        if(!empty && size%sub_size == 0){
            struct Node * aux = (struct Node *) malloc(sizeof(struct Node));
            aux->a = node.a;
            aux->b = &node;

            node.b =
            node.b->a =
        }
        node.e[size++];
        empty = false;
    }
};
/*
class HiperIndex(){
    unsigned hi[];
  public:
    HiperIndex(unsigned vec[]){
        hi = vec[];
        dim =
    }
    HiperIndex(List<unsigned> vec){
        hi = vec[];
    }



}
template <class T> class Matrix {
  private:
    T* m;
  public:
    unsigned dim[];
    static unsigned access_element(unsigned pos[]){
        return hilbert_v2d(dim[0]*dim[1], pos);
    }
    Matrix(unsigned dim[]){
        m = T[dim[0]*dim[1]];


    }
    T operator[](unsigned pos[]){
        return m[access_element(pos)];
    }
    operator String() {
        string answer;

        return answer;
    }
    void print() {
        unsigned
    }
};
*/
class Node{
  public:
    void ** e;
    Node *b, *a;
} node;
int main(void)
{
    Node node = Node();
    /*Range r;
    Matrix m = new Matrix({4,4})
    for(r = Range((int[]) {0,0}, (int[]) {4,4}); )
    for(x = 0; x < 4; x++){
        for(y = 0; y < 4; y++){
            m[{x,y}] = x+y+1;
        }
    }
    m.print();
    */
   return 0;
}
