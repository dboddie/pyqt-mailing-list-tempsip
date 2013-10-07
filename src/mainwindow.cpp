/*
 * mainwindow.cpp - Implementation of a main window class.
 *
 * Copyright (C) 2013 David Boddie <david.boddie@met.no>
 *
 * This file is part of the pyqt-wrapped-app example.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtGui>
#include "logindialog.h"
#include "mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    // Set a default dialog.
    m_dialog = new LoginDialog();

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *loginAction = fileMenu->addAction(tr("&Login"));
    connect(loginAction, SIGNAL(triggered()), SLOT(showLoginDialog()));

    QAction *quitAction = fileMenu->addAction(tr("E&xit"));
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));
}

MainWindow::~MainWindow()
{
}

LoginDialog *MainWindow::getLoginDialog() const
{
    return m_dialog;
}

void MainWindow::setLoginDialog(LoginDialog *dialog)
{
    m_dialog = dialog;
}

void MainWindow::showLoginDialog()
{
    m_dialog->exec();
}
