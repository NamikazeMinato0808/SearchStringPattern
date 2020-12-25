#include <iostream>
#include <string>
using namespace std;

void fCreateNEXT(int*&NEXT, string P){
	cout<<"\nQua trinh tao mang NEXT: \n";
	int m=P.size();
	NEXT=new int[m+1];
	NEXT[0]=-1;
	int j=-1;
	for(int i=1;i<=m;i++){
		cout<<"i = "<<i<<" ";
		if(j==-1){
			cout<<"TH1\n";
			j=0;
			NEXT[i]=0;
		}
		else if(P[j]==P[i-1]){
			cout<<"TH2: "<<"P["<<j<<"] = "<<P[j]<<" ; "<<"P["<<i-1<<"] = "<<P[i-1]<<endl;
			j++;
			NEXT[i]=j;
		}
		else{
			cout<<"TH3: "<<"P["<<j<<"] = "<<P[j]<<" ; "<<"P["<<i-1<<"] = "<<P[i-1]<<" ; NEW j = "<<NEXT[j]<<endl;
			j=NEXT[j];
			i--;
		}
	}
	cout<<"Mang NEXT: ";
	for(int i=0;i<m;i++) cout<<NEXT[i]<<" ";
	cout<<endl<<endl;
}

void fSearch(string T, string P){
	int* NEXT=NULL;
	fCreateNEXT(NEXT, P);
	cout<<"Qua trinh so sanh:\n";
	int i=0;
	int j=0;
	int n=T.size();
	int m=P.size();
	while(i<n){
		cout<<"Qua trinh so khop dang dien ra tai vi tri "<<i<<endl;
		cout<<"T["<<i+j<<"] = "<<T[i+j]<<" ; "<<"P["<<j<<"] = "<<P[j]<<endl;
		if(T[i+j]==P[j]){
			cout<<"Giong nhau\n";
			j++;
			if(j==m){
				cout<<"Khop tai vi tri "<<i<<endl;
				int j1=NEXT[j];
				int i1=i+j-j1;
				i=i1;
				j=j1;
			} 
		}
		else{
			cout<<"Khac nhau. ";
			if(j==0){
				cout<<"Dich chuyen cua so 1 don vi\n";
				i++;
				j=0;
			}
			else{
				cout<<"Dich chuyen cua so nho NEXT["<<j<<"] = "<<NEXT[j]<<endl;
				int j1=NEXT[j];
				int i1=i+j-j1;
				i=i1;
				j=j1;
			}
		}
	}
}

int main(){
	string P, T;
	cout<<"Chuong trinh tim kiem vi tri chuoi Pattern trong chuoi Template\n";
	cout<<"Gia su chuoi Template dai n, chuoi Pattern dai m thi do phuc tap thuat toan la O(n+m)\n";
	cout<<"Thuat toan Morris - Pratt: \n";
	cout<<"Nhap chuoi Template: ";
	getline(cin, T);
	cout<<"Nhap chuoi Pattern: ";
	getline(cin, P);
	fSearch(T, P);
}
