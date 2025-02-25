#include "MainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    // 设置窗口标题和大小
    setWindowTitle("P2P 语音聊天");
    resize(400, 300);

    // 创建按钮
    startButton = new QPushButton("开始通话", this);
    endButton = new QPushButton("结束通话", this);
    endButton->setEnabled(false);

    // 创建日志显示框
    logTextEdit = new QTextEdit(this);
    logTextEdit->setReadOnly(true);

    // 布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(startButton);
    layout->addWidget(endButton);
    layout->addWidget(logTextEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // 连接按钮信号和槽
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startCall);
    connect(endButton, &QPushButton::clicked, this, &MainWindow::endCall);
}

MainWindow::~MainWindow() {}

void MainWindow::startCall() {
    logTextEdit->append("通话已开始...");
    startButton->setEnabled(false);
    endButton->setEnabled(true);
}

void MainWindow::endCall() {
    logTextEdit->append("通话已结束。");
    startButton->setEnabled(true);
    endButton->setEnabled(false);
}