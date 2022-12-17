#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <math.h>
#include <stdlib.h>
#include "mainwindow.h"

#define NUMBOLAS 6

MainWindow::MainWindow(QWidget * parent) :   QMainWindow(parent) { 


	
	resize(800,600);
	
	crearBolas();
		
	temporizador = new QTimer();
	temporizador->setInterval(16);
	temporizador->setSingleShot(false);
	temporizador->start();

	//bola = new Bola(posX,posY,40.0,40.0);

	//bola2 = new Bola(300,600,40.0,40.0);
	//bola2->velX = 10;
	//bola2->velY = 10;
	
	connect(temporizador,SIGNAL(timeout()),
		this,SLOT(slotTemporizador()));
		
}
void MainWindow::crearBolas(){


	for(int i=0 ; i<NUMBOLAS; i++ ){

		
		float posX = random()% width();
		float posY = random()% height();
		
		Bola *nueva = new Bola(posX,posY,40.0,40.0);

		nueva->velX = (float) (rand()%100) /50-1;
		nueva->velY = (float) (rand()%100) /50-1;

		bolas.append(nueva);
	
	}
}
/*
void MainWindow::keyPressEvent(QKeyEvent *event){

	int tecla = event->key();
	
	

	if(tecla ==Qt::Key_Any){
	
	 if(velY < 0){
	 velY++;
	 }
	 if(velY > 0){
	 velY--;
	 }
	 if(velX < 0){
	 velX++;
	 }
	 if(velX > 0){
	 velX--;
	 }
	 
	}
		
	if(tecla ==Qt::Key_A){
	
	 //posX = posX -5;
	 velX--;
	}
	if(tecla ==Qt::Key_D){
	
	 //posX = posX +5;
	 velX++;
	}
	if(tecla ==Qt::Key_W){
	
	 //posY = posY -5;
	 velY--;
	}
	if(tecla ==Qt::Key_S){
	
	 //posY = posY +5;
	 velY++;
	}
	
	


}
*/
void MainWindow::paintEvent ( QPaintEvent * event ){
	QPainter pintor(this);

	//pintor.fillRect(posX,posY,40,40,"Red");
    //pintor.drawLine(0,y,width(),y);
    
    QBrush brush(QColor("red"));
    pintor.setBrush(brush);

    
    for(int i=0 ; i< bolas.size() ; i++ ){
    
    	pintor.drawEllipse(*bolas.at(i));
    
    }
    
    

}

void MainWindow::slotTemporizador(){


	int anchura = width();
	int altura = height();
	
	/*
	if( posX >= anchura - 40 || posX <= 0 ){
		velX = velX * -1;
	}
	
	if( posY >= altura - 40 || posY <= 0 ){
		velY = velY * -1;
	}
	*/
	
	
	for(int i=0 ; i< bolas.size() ; i++ ){
	


		
		if( bolas.at(i)->posX >= anchura - 40){
			bolas.at(i)->velX = -fabs(bolas.at(i)->velX);
		}
		if( bolas.at(i)->posX <= 0 ){
			bolas.at(i)->velX = fabs(bolas.at(i)->velX);
		}
		if( bolas.at(i)->posY >= altura - 40){
			bolas.at(i)->velY = -fabs(bolas.at(i)->velY);
		}
		if( bolas.at(i)->posY <= 0 ){
			bolas.at(i)->velY = fabs(bolas.at(i)->velY);
		}


		
		
	
	calcularColisiones(bolas.at(i),i);
	
	bolas.at(i)->posX = bolas.at(i)->posX + bolas.at(i)->velX;
	bolas.at(i)->posY = bolas.at(i)->posY + bolas.at(i)->velY;
 
	bolas.at(i)->moveTo(bolas.at(i)->posX, bolas.at(i)->posY);
	
	
	}
	
/*
		if (bola->intersects(*bola2))
		{
			qDebug() << "hola ";

			bola->velX *= -1;
			bola->velY *= -1;

			bola2->velX *= -1;
			bola2->velY *= -1;
		}
		*/



	update();

}
void MainWindow::calcularColisiones(Bola *bola,int index){

	for(int i=0 ; i< bolas.size() ; i++ ){

		if (bolas.at(i)->intersects(*bola) && i!=index)
		{
			qDebug() << "Colision ";

			bolas.at(i)->velX *= -1;
			bolas.at(i)->velY *= -1;

			bola->velX *= -1;
			bola->velY *= -1;

			bolas.at(i)->posX = bolas.at(i)->posX + bolas.at(i)->velX;
			bolas.at(i)->posY = bolas.at(i)->posY + bolas.at(i)->velY;
 
			bolas.at(i)->moveTo(bolas.at(i)->posX, bolas.at(i)->posY);
			
		}

	}

}
