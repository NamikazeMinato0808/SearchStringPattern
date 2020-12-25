#include <iostream>
#include <string>
using namespace std;

void fCreateLPS(int*&LPS, string P){
	LPS=new int[P.size()];
	LPS[0]=0;
	int m=P.size();
	for(int i=1;i<m;i++){
		cout<<"i= "<<i<<":\n";
		int j=LPS[i-1];
		while(true){
			cout<<"   j = "<<j<<": P["<<i<<"] = "<<P[i]<<" ; P["<<j<<"] = "<<P[j]<<".";
			if(P[j]==P[i]) {
				cout<<" Giong nhau. LPS["<<i<<"] = "<<j+1<<endl;
				LPS[i]=j+1;
				break;
			}
			else if(j==0){
				cout<<" Khong the so khop. LPS["<<i<<"] = 0\n";
				LPS[i]=0;
				break;
			}
			cout<<" Khac nhau. Tiep tuc so khop voi j = "<<LPS[j-1]<<endl;
			j=LPS[j-1];
		}
	}
	cout<<"Mang LPS: ";
	for(int i=0;i<m;i++){
		cout<<LPS[i]<<" ";
	}
	cout<<endl;
}

void fSearch(string T, string P){
	cout<<"Qua trinh tao LPS:\n";
	int*LPS=NULL;
	fCreateLPS(LPS, P);
	int n=T.size();
	int m=P.size();
	cout<<endl<<"Qua trinh so khop:\n";
	int i=0;
	int j=0;
	while(i<n){
		cout<<"Qua trinh so khop tai vi tri "<<i<<endl;
		cout<<"T["<<i+j<<"] = "<<T[i+j]<<" ; "<<"P["<<j<<"] = "<<P[j]<<endl;
		if(T[i+j]!=P[j]){
			cout<<"Khac nhau. ";
			if(j==0){
				cout<<"Khong the so khop tiep duoc. Dich chuyen cua so len 1 don vi\n";
				i++;
				j=0;
			}
			else{
				cout<<"Co the so khop tiep. ";
				int j1=LPS[j-1];
				int i1=i+j-j1;
				i=i1;
				j=j1;
				cout<<"NEW i = "<<i1<<" ; NEW j = "<<j1<<endl;
			}
		}
		else{
			cout<<"Giong nhau. Tang len 1 don vi\n";
			j++;
			if(j==m){
				cout<<"Khop tai vi tri: "<<i<<endl;
				int j1=LPS[j-1];
				int i1=i+j-j1;
				i=i1;
				j=j1;
			}
		}
	}
}

int main(){
	cout<<"Thuat toan tim kiem vi tri chuoi Pattern trong chuoi Template\n";
	cout<<"Gia su chuoi Pattern dai m, chuoi Template dai n, thi do phuc tap thuat toan la O(n+m)\n";
	cout<<"Thuat toan KMP: \n";
	string T, P;
	cout<<"Nhap chuoi Template: ";
	getline(cin, T);
	cout<<"Nhap chuoi Pattern: ";
	getline(cin, P);
	fSearch(T,P);
}
