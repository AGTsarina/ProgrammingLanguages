#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int getDigitsCount(int zn, int&maxDigit){
//pair <int/*кол-во (main)*/, int/*max(secondary)*/> chys(int zn){
    int co = 0;
    maxDigit = 0;
    while(zn>0){
        co++;
        int g = zn % 10;
        maxDigit = max(maxDigit, g);
        zn = zn / 10;
    }    
    return co;
}


float f(float e, int &c)
{
	float res = 0;
	float slag = 1;
	/*int*/ c = 0;
	for (int n = 0; slag > e; n++)
	{
		slag = slag*(n + 1) / (4 * n + 2);
		res += slag;
		c++;
	}
	//printf("%d ", c);
	return res;
}

int main()
{
	float e = 1.0e-9;//	scanf_s("%d", &e);
    int c = 0;
	printf("S = %e\t", f(e, c));
    printf("n = %d\n", c);
	return 0;
}
/*int main(){
    int x, maxd;
    cin >> x;
    cout << getDigitsCount(x, maxd)<< " ";
    cout << maxd << endl;
    return 0;
}*/