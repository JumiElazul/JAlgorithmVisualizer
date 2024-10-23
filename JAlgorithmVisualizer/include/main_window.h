#ifndef JUMI_J_ALGORITHM_VISUALIZER_MAIN_WINDOW_H
#define JUMI_J_ALGORITHM_VISUALIZER_MAIN_WINDOW_H
#include <QMainWindow>

class QWidget;

namespace jumi
{
    const int minimum_toolbar_width = 200;

    class main_window : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit main_window(QWidget* parent = nullptr) noexcept;

    private slots:

    private:
        QWidget* _visualization_widget;

        void create_left_sidebar();
        void create_right_sidebar();
    };

}

#endif