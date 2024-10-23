#include <QApplication>
#include "main_window.h"

namespace jumi
{
    int main(int argc, char** argv)
    {
        QApplication app(argc, argv);
        main_window window;
        return app.exec();
    }
}

int main(int argc, char** argv)
{
    return jumi::main(argc, argv);
}