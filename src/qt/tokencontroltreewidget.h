// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020 The VibofChain Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VIBOFCHAIN_QT_TOKENCONTROLTREEWIDGET_H
#define VIBOFCHAIN_QT_TOKENCONTROLTREEWIDGET_H

#include <QKeyEvent>
#include <QTreeWidget>

class TokenControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit TokenControlTreeWidget(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // VIBOFCHAIN_QT_TOKENCONTROLTREEWIDGET_H
