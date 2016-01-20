#include <iostream>

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
int * hilbert_d2v(int n, int d) {
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
}
