#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+10;

int n;
int a[maxn];
int left,right;
int kq;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	kq=1;int l=1;left=right=1;
	for(int i=2;i<=n;i++){
		if (a[i-1]<=a[i]) l++;
		else l=1;
		if (kq<l){
			kq=l;
			left=i-l+1;
			right=i;
		}
	}
	printf("Kq=%d\n",kq);
	for(int i=left;i<=right;i++) printf("%d ",a[i]);
}
