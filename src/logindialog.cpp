/*
 * logindialog.cpp - Implementation of a login dialog.
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

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    QLineEdit *nameEdit = new QLineEdit();
    QLineEdit *passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow(tr("User name:"), nameEdit);
    layout->addRow(tr("Password:"), passwordEdit);
}

LoginDialog::~LoginDialog()
{
}
