#include <iostream>
#include <fstream>
//#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;

int main(int argc, char **argv)
{
	std::ifstream iFile("input.txt", std::ios::in);
	Point_2 p1, p2;

	QApplication app(argc, argv);
	QGraphicsScene scene;
	scene.setSceneRect(0,0, 300, 300);
	while(iFile >> p1)
		if (iFile >> p2)		//checks if even number of lines are there and we don't get an error
			scene.addLine(QLineF(p1.x(),p1.y(),p2.x(),p2.y()));

	QGraphicsView* view = new QGraphicsView(&scene);
	CGAL::Qt::GraphicsViewNavigation navigation;
	view->installEventFilter(&navigation);
	view->viewport()->installEventFilter(&navigation);
	view->setRenderHint(QPainter::Antialiasing);
	view->show();
	return app.exec();
}



