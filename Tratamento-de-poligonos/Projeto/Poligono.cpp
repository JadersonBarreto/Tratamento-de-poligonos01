#include "Poligono.h"
#include "Ponto.h"
#include <cmath>
#include <iostream>

using namespace std;

Poligono::Poligono()
{
    nVertices = 0;

}Poligono::~Poligono()
{
}
void Poligono::addVertice(float x, float y)
{
    p[nVertices].setX(x);
    p[nVertices].setY(y);
    nVertices++;
}
int Poligono::getVertice(){
    return nVertices + 0;
}
float Poligono:: area(){
    float soma1=0,soma2 = 0,somaTotal=0;
    int i;
    for(i= 0; i < nVertices-1;i++){
        soma1+=  p[i].getX()*p[i+1].getY();
    }

    soma1 += p[i].getX()*p[0].getY();



    for(i= 0; i < nVertices-1;i++){
        soma2+=p[i].getY()*p[i+1].getX();
    }
    soma2 += p[i].getY()*p[0].getX();

    return (abs(soma1 - soma2))/2.0;


}
void Poligono::mover(float x, float y){
    for(int i=0;i<nVertices;i++){
        p[i]=p[i].translada(x,y);
    }
}
Ponto Poligono::centroide(){
    float somaX=0;
    float somaY=0;
    Ponto pcentro;
    int i;
    for(i= 0; i < nVertices-1;i++){
        somaX+=  (p[i].getX()*p[i+1].getY() - p[i].getY()*p[i+1].getX())*(p[i].getX() + p[i+1].getX());
    }
    somaX +=(p[i].getX()*p[0].getY() - p[i].getY()*p[0].getX())*(p[i].getX() + p[0].getX());
    pcentro.setX( somaX/(6*area()));

    for(i= 0; i < nVertices-1;i++){
        somaY+=  (p[i].getX()*p[i+1].getY() - p[i].getY()*p[i+1].getX())*(p[i].getY() + p[i+1].getY());
    }
    somaY +=(p[i].getX()*p[0].getY() - p[i].getY()*p[0].getX())*(p[i].getY() + p[0].getY());
    pcentro.setY( somaY/(6*area()));

    return pcentro;

}

void Poligono::rot(double ang){
    for(int i=0;i<nVertices;i++){
        double a = (M_PI*ang)/180.0;
        float x = cos(a)*p[i].getX() - sin(a)*p[i].getY();
        float y = sin(a)*p[i].getX() + cos(a)*p[i].getY();
        p[i].setX(x);
        p[i].setY(y);
    }
}
void Poligono::rot(double ang,int px,int py){
    mover(-px,-py);
    rot(ang);
    mover(px,py);
}
void Poligono::rot(double ang,Ponto p){
    mover(-p.getX(),-p.getY());
    rot(ang);
    mover(-p.getX(),-p.getY());
}

void Poligono::print(){
    for(int i=0;i<nVertices;i++){
        p[i].imprime();
        cout<<"->";
    }
    p[0].imprime();
}
