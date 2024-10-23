#include "main_window.h"
#include <QPushButton>
#include <QListWidget>
#include <QLayout>
#include <QDockWidget>

namespace jumi
{

    main_window::main_window(QWidget* parent) noexcept
        : QMainWindow(parent)
        , _visualization_widget(new QWidget(this))
    {
        setCentralWidget(_visualization_widget);
        setWindowTitle("Jumi's Algorithm Visualizer");
        resize(1280, 720);

        QFont georgia("Georgia", 20);
        setFont(georgia);

        create_left_sidebar();
        create_right_sidebar();

        show();
    }

    void main_window::create_left_sidebar()
    {
        QDockWidget* left_dock = new QDockWidget("Algorithms", this);
        left_dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        left_dock->setFeatures(left_dock->features() & ~QDockWidget::DockWidgetClosable);
        left_dock->setFeatures(left_dock->features() & ~QDockWidget::DockWidgetFloatable);
        left_dock->setFeatures(left_dock->features() & ~QDockWidget::DockWidgetMovable);

        QListWidget* algorithm_list = new QListWidget(left_dock);
        algorithm_list->addItems({ "Quicksort", "Merge Sort", "Dijkstra's Algorithm", "A* Search" });
        left_dock->setWidget(algorithm_list);
        left_dock->setMinimumWidth(minimum_toolbar_width);

        addDockWidget(Qt::LeftDockWidgetArea, left_dock);
    }

    void main_window::create_right_sidebar()
    {
        QDockWidget* right_dock = new QDockWidget("Parameters", this);
        right_dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

        right_dock->setFeatures(right_dock->features() & ~QDockWidget::DockWidgetClosable);
        right_dock->setFeatures(right_dock->features() & ~QDockWidget::DockWidgetFloatable);
        right_dock->setFeatures(right_dock->features() & ~QDockWidget::DockWidgetMovable);

        QWidget* param_widget = new QWidget(right_dock);
        QVBoxLayout* layout = new QVBoxLayout(param_widget);

        param_widget->setLayout(layout);
        right_dock->setWidget(param_widget);
        right_dock->setMinimumWidth(minimum_toolbar_width);

        addDockWidget(Qt::RightDockWidgetArea, right_dock);
    }

}