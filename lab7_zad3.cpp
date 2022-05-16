//Потребно е да конструирате абстракна класа Shape со само еден параметар:
//
//страна (int)
//Конструктори:
//
//Shape()
//Shape(int a)
//И виртуелните методи:
//
//double plostina()
//void pecati()
//int getType()
//Од таа класа вие треба да конструирате 3 изведени класи:
//
//Square
//        Circle
//Triangle
//        Изведените класи немаат дополнителни парамтери, туку ја наследуваат страната од Shape
//
//        Конструктори:
//
//Конструкторот на изведените класи ќе зема еден аругмент, страната на фигурата.
//
//При пишување на конструкторот на изведените класи да се искористи констукторот на родител класата
//
//Методи:
//
//Секоја од класите си има своја формула за plostina() соодветна за нивната геометриска фигура
//
//        Формула за плоштина на квадрат а * a
//Формула за плоштина на круг 3.14 * a * a
//Формула за плоштина на триаголник (sqrt(3)/4) * side * side
//За pecati() методот упатете се кон outputot за тест случајите.
//
//getType() методот треба да враќа:
//
//1 за Square
//2 за Circle
//3 за Triangle
//Поени: 5
//
//--
//
//Дефинирајте го методот void checkNumTypes(Shape** niza, int n) така што ќе испечати во три реда колку квадрати, кругови и триаголници има во низата.
//
//Поени: 2
//
//--
//
//Покрај тоа треба да ја допишете Main класата така што ќе алоцирате динамичка низа од покажувачи кон класата Shape.
//
//Потоа кај секој покажувач од низата зависно од дадениот input да алоцирате објект од една од трите изведени класи.
//
//Input:
//
//Прво се добива n - големината на динамичката низа. Потоа n пати се добиваат пар цели броеви t i a, каде што t е типот на објектот и а е страната на објектот.
//
//Пример:
//
//3
//
//1 3 //квадрат со страна со должина 3
//
//2 2 //круг со страна со должина 2
//
//3 1 //триаголник со страна со должина 1
//
//Поени: 3
//
//--
#include <iostream>
#include <cmath>
using namespace std;

class Shape{
protected:
    int a;
public:
    Shape(){
        a=0;
    }
    Shape(int a){
        this->a=a;
    }
    virtual double plostina()=0;
    virtual void pecati()=0;
    virtual int getType()=0;
};
/*
 * vo ovie klasi (izvedeni od apstraktnata) treba da imas
 * konstruktor, zatoa shto se povikuva toj vo main (potsetise, koga
 * kreirash objekt od glavnata klasa, istiot toj go opishuvash preku
 * objekt od sporednata t.e. koristish konstruktor). Vo ovie klasi mozi
 * konst. da e prazen
 */
class Square: public Shape{
public:
    Square(){}
    Square(int a) : Shape(a){};
    double plostina(){
        return a*a*1.0;
    }
    int getType(){
        return 1;
    }
    void pecati(){
        cout<<"Kvadrat so plostina = "<<plostina()<<endl;
    }

};
class Circle: public Shape{
public:
    Circle(){}
    Circle(int a) : Shape(a){}
    double plostina(){
        return 3.14 * a * a;
    }
    int getType(){
        return 2;
    }
    void pecati(){
        cout<<"Krug so plostina = "<<plostina()<<endl;
    }
};
class Triangle: public Shape{
public:
    Triangle(){}
    Triangle(int a) : Shape(a){};
    double plostina(){
        return (sqrt(3)/4) * a * a*1.0;
    }
    int getType(){
        return 3;
    }
    void pecati(){
        cout<<"Triagolnik so plostina = "<<plostina()<<endl;
    }
};

//reshavam so dynamic cast
void checkNumTypes(Shape** shapes, int n){
    int s=0, c=0, t=0;
    for(int i=0; i<n; i++){
        Square *sq = dynamic_cast<Square *>(shapes[i]);
        if(sq!=nullptr)
            s++;
        Circle *ci = dynamic_cast<Circle *>(shapes[i]);
        if(ci!=nullptr)
            c++;
        Triangle *tr = dynamic_cast<Triangle *>(shapes[i]);
        if(tr!=nullptr)
            t++;
    }
    cout<<"Broj na kvadrati vo nizata = "<<s<<endl;
    cout<<"Broj na krugovi vo nizata = "<<c<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<t<<endl;
}

int main(){


    int n;
    cin >> n;
    //! deka shapes e niza, ke mora?
    Shape **shapes = new Shape*[n];
    int classType;
    int side;

    for(int i = 0; i < n; ++i){

        cin >> classType;
        cin >> side;

        if(classType==1){
            shapes[i]=new Square(side); //constr
        }
        if(classType==2){
            shapes[i]=new Circle(side); //constr
        }
        if(classType==3){
            shapes[i]=new Triangle(side); //constr
        }

    }

    for(int i = 0; i < n; ++i){
        shapes[i]->pecati();
    }

    checkNumTypes(shapes, n);


    return 0;
}