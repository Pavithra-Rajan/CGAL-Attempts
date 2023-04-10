#include <CGAL/Triangle_2.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/intersections.h>
#include <QGraphicsTextItem>
#include <QPolygonF>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef K::Triangle_2 Triangle_2;

int main(int argc, char **argv)
{
        std::ifstream iFile("input.txt", std::ios::in);
        QApplication app(argc, argv);
        QGraphicsScene scene;
        scene.setSceneRect(0, 0, 500, 400);

        Point_2 p1, p2, p3;
        iFile >> p1;
        iFile >> p2;
        iFile >> p3;

        QPolygonF polygon;
        Triangle_2 triangle(Point_2(p1.x(), p1.y()), Point_2(p2.x(), p2.y()), Point_2(p3.x(), p3.y()));
        polygon << QPointF(triangle.vertex(0).x(), triangle.vertex(0).y())
                << QPointF(triangle.vertex(1).x(), triangle.vertex(1).y())
                << QPointF(triangle.vertex(2).x(), triangle.vertex(2).y());
        scene.addPolygon(polygon);

        double area = std::abs(triangle.area());

        std::cout << "Area of the triangle is: " << area << std::endl;
        std::stringstream ss;
        ss << "Area of the triangle is: " << area << std::endl;
        std::string str = ss.str();

        QGraphicsTextItem *text = scene.addText(QString::fromStdString(str));
        text->setPos(0, 200);

        QGraphicsView *view = new QGraphicsView(&scene);
        CGAL::Qt::GraphicsViewNavigation navigation;
        view->installEventFilter(&navigation);
        view->viewport()->installEventFilter(&navigation);
        view->setRenderHint(QPainter::Antialiasing);
        view->show();
        return app.exec();
}
