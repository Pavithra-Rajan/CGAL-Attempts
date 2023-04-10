#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 

int main(int argc, char **argv)
{
	QApplication app(argc, argv); //create a new QT GUI application
	QGraphicsScene scene; //create a QT scene to display point
	scene.setSceneRect(0,0, 500, 300); //set scene size

	//add a point in the scene
	 scene.addEllipse(100, 100, 15, 15);
	//display the scene
	 QGraphicsView* view = new QGraphicsView(&scene);
	 CGAL::Qt::GraphicsViewNavigation navigation;
	 view->installEventFilter(&navigation);
	 view->viewport()->installEventFilter(&navigation);
	 view->setRenderHint(QPainter::Antialiasing);
	 view->show();
	 return app.exec();
}

