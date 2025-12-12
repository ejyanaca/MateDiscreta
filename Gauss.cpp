#include<iostream>
#include<iomanip>
using namespace std; 

int main(){
    int n;  
    cout<<"\nIngrese el orden de la matriz nxn: "; 
    cin>>n; 
    if(n<=0){
        cout<<"ERROR: Orden de la matriz invalida"<<endl; 
    }else{
        float A[n][n]; 
        float I[n][n]; 
        float aux,pivote; 
	    cout<<"\nIngrese los elementos de la matriz : "<<endl; 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<"Ingrese A["<<i+1<<"]["<<j+1<<"]: "; 
                cin>>A[i][j]; 
                if(i==j){
                    I[i][j]=1;
                }else{
                    I[i][j]=0;
                }
            }
        }

        cout << "\nMatriz creada y Matriz Identidad:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout <<"\t"<<A[i][j];
            }
            cout <<" | ";
            for(int j = 0; j < n; j++){
                cout <<I[i][j] <<"\t";
            }
            cout << endl; 
        }

        for(int i=0; i<n; i++){
            pivote = A[i][i];

            for(int k=0; k<n; k++){
                A[i][k]=A[i][k]/pivote;
                I[i][k]=I[i][k]/pivote;
            }
            for(int j=0; j<n; j++){
                if(i != j){
                    aux = A[j][i];
                    for(int k=0; k<n; k++){
                        A[j][k]= A[j][k]-aux*A[i][k];
                        I[j][k]= I[j][k]-aux*I[i][k];
                    }
                }   
            }
        }
        cout << fixed << setprecision(2);
        cout << "\nMatriz creada reducida e Inversa al costado:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout <<"\t"<<A[i][j];
            }
            cout << " |  ";
            for(int j = 0; j < n; j++){
                cout<<I[i][j]<<"\t";
            }
            cout << endl;
        }
    }
    return 0;
}