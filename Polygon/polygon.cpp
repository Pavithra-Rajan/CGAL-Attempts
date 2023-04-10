#include <iostream>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygonF>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
int main(int argc, char **argv)
{
	std::ifstream iFile("input.txt", std::ios::in);
	Point_2 p1;

	QApplication app(argc, argv);
	QGraphicsScene scene;
	scene.setSceneRect(0, 0, 300, 300);
	QPolygonF polygon;

	while (iFile >> p1)
		polygon << QPointF(p1.x(), p1.y());

	scene.addPolygon(polygon);

	QGraphicsView *view = new QGraphicsView(&scene);
	CGAL::Qt::GraphicsViewNavigation navigation;
	view->installEventFilter(&navigation);
	view->viewport()->installEventFilter(&navigation);
	view->setRenderHint(QPainter::Antialiasing);
	view->show();
	return app.exec();
}
