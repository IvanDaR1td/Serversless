#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startCall();
    void endCall();

private:
    QPushButton *startButton;
    QPushButton *endButton;
    QTextEdit *logTextEdit;
};

#endif // MAINWINDOW_H