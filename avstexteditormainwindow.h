#ifndef AVSTEXTEDITORMAINWINDOW_H
#define AVSTEXTEDITORMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class AVSTextEditorMainWindow; }

QT_END_NAMESPACE

class AVSTextEditorMainWindow : public QMainWindow
{

    Q_OBJECT

public:

    AVSTextEditorMainWindow(QWidget *parent = nullptr);

    ~AVSTextEditorMainWindow();

    void aboutInfo();

private slots:

    void OpenTriggered();

    void SaveAsTriggered();

    void InfoTriggered();

    void AboutTriggered();

    void ClearAllTriggered();

private:

    Ui::AVSTextEditorMainWindow *ui;

};

#endif // AVSTEXTEDITORMAINWINDOW_H
