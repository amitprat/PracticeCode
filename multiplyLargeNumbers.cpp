//Multiply two number using simple approach

#include	<iostream>
using namespace std;


void mul(char num1[], char num2[], int n1, int n2, char res[]) {
	int tmp[n1+n2];
	for(int i=n1-1;i>=0;i--) {
		for(int j=n2-1;j>=0;j--) {
			tmp[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
		}
	}

	for(int k=n1+n2-1;k>0;k--) {
		tmp[k-1] += tmp[k]/10;	
		tmp[k] = tmp[k]%10;
	}

	int i = 0, j =0;
	while(tmp[i] == 0)	i++;
	for(;i<n1+n2;i++) {
		res[j++] = tmp[i]+'0';
	}		
}
int main() {
	char num1[] = "999";
	char num2[] = "9999";

	int n1 = strlen(num1);
	int n2 = strlen(num2);
	char res[n1+n2+1];
	memset(res,'\0',n1+n2+1);

	mul(num1,num2,n1,n2,res);
	cout<<res<<endl;
	return 0;
}
