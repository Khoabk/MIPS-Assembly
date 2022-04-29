#include <iostream>
#include <fstream>


using namespace std;












class Matrix{

    int **root= nullptr;
    int h{};
    int w{};
    bool del=false;


public:

    Matrix(int ha=0, int wa=0);
    Matrix(const string& data);
    ~Matrix();
    int getHight() const{return h;}
    int getWidth() const{return w;}
    double get_dif(Matrix& b);
    int& insert(int x, int y);
    Matrix operator*(Matrix&b);

    void display();

};



double Matrix::get_dif(Matrix &b) {


    if(h!=b.getHight()||w!=b.getWidth()||root==nullptr)throw false;


    double diff=0;

    for(int i=0; i<h;i++)
        for(int j=0; j<w; j++)
            if(root[j][i]!=b.root[j][i])diff++;

    return diff/(h*w);
}




Matrix Matrix::operator*(Matrix& b){



    if(this->getWidth()!= b.getHight())throw false;


     Matrix c(this->getHight(),b.getWidth());

     int sum=0;
    for(int i=0; i<this->getHight(); i++)
    { for(int j=0; j<b.getWidth(); j++) {
            for (int k = 0; k < this->getWidth(); k++) {
                c.insert(j, i) = this->insert(k, i) * b.insert(j, k) + c.insert(j, i);
                int a = this->insert(k, i);
                int h = b.insert(j, k);
                sum = sum + a * h;
            }
            sum=0;
        }

    }

c.del=true;

return c;

}


void Matrix::display() {

    if(root== nullptr)return;

    for(int i=0; i<h; i++) {
        for (int j = 0; j < w; j++)
            cout <<root[j][i]<<" ";
        cout<<endl;
    }
}


int& Matrix::insert(int x, int y) {

    return root[x][y];
}




Matrix::~Matrix(){

    if(root!= nullptr&&!del){

        for(int i=0; i<w; i++)delete[] root[i];

        delete[] root;

    }



}



Matrix::Matrix(const string& data) {

    ifstream ifs;

    ifs.open(data);

    //get size of matrix
    ifs>>h;
    ifs>>w;

    //create matrix
    root= new int*[w];
    for(int i=0; i<w; i++)
        root[i]=new int[h];

    //load data to matrix
    for(int i=0;i<h;i++)//first height
    {
        for(int j=0;j<w;j++)
        {  int a; ifs>>a;   this->insert(j,i)=a;}
    }


}


Matrix::Matrix(int ha, int wa) {

    h=ha;
    w=wa;


    if(h==0||w==0)return;

    root= new int*[w];
    for(int i=0; i<w; i++)
    {root[i]=new int[h];
    for(int j=0;j<h; j++)
        root[i][j]=0;
    }

}












int main() {

Matrix A("A.txt");

Matrix B("B.txt");

Matrix D("result.txt");
Matrix C;
try{



    A.display();
    cout<<endl;
    B.display();


    C=A*B;

  cout<<C.get_dif(D)<<endl;
   C.display();
}
catch(bool e)
{
    cout<<"Mismatch"<<endl;
}



    return 0;
}
