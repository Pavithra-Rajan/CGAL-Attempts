#include <iostream>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QPen> 				//QT header for colors and styles
#include <CGAL/Cartesian.h> 	// CGAL header for Cartesian coordinates
#include <CGAL/Point_2.h> 		// CGAL header for 2D points
//Define datatype Point_2

typedef CGAL::Cartesian<double> K;  // define type K as Cartesian coordinate
typedef K::Point_2 Point_2; 		// define type Point_2 as 2D Cartesian point

int main(int argc, char **argv)
{
	 Point_2 p; 										//Declare a variable of type Point_2
	 std::ifstream iFile("input.txt", std::ios::in); 	//Open file for reading
	 QApplication app(argc, argv);
	 QGraphicsScene scene;
	 scene.setSceneRect(0,0, 500, 300); 				//Set window size of your choice
	 QPen pen; 											//Declare a variable of type Pen
	 pen.setColor(Qt::red); // Set the color of pen as red
	 
	 while(iFile >> p) //read input points into variable p
			scene.addEllipse(p.x(), p.y(), 5, 5, pen, QBrush(Qt::red)); 
			//add a point in the QT window by drawing a circle of small diamater
			//Qbursh fills with the colour given as parameter

	 QGraphicsView* view = new QGraphicsView(&scene);
	 CGAL::Qt::GraphicsViewNavigation navigation;
	 view->installEventFilter(&navigation);
	 view->viewport()->installEventFilter(&navigation);
	 view->setRenderHint(QPainter::Antialiasing);
	 view->show();
	 return app.exec();
}
