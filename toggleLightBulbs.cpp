#include	<iostream>
using namespace std;

int numBulbs = 10;
int sum[10];

void update(int idx, int val) {
	while(idx <= numBulbs) {
		sum[idx] += val;
		idx += (idx & -idx);
	}
}

int read(int idx) {
	int ans = 0;
	while(idx) {
		ans += sum[idx];
		idx -= (idx & -idx);
	}

	return ans;
}

void toggle(int s,int e) {
	update(s,1);
	update(e+1,-1);
}

bool isOn(int idx) {
	return read(idx)%2 == 1;
}
int main() {
	int s = 2;
	int e = 5;
	for(int i=0;i<numBulbs;i++)
		cout<<"Status("<<i<<")="<<isOn(i)<<endl;
	cout<<endl;

	toggle(1,2);
	toggle(3,5);
	toggle(8,9);
	toggle(5,8);

	for(int i=0;i<numBulbs;i++)
		cout<<"Status("<<i<<")="<<isOn(i)<<endl;
	cout<<endl;

	return 0;
}
