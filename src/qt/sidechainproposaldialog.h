// Copyright (c) 2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECHAINPROPOSALDIALOG_H
#define SIDECHAINPROPOSALDIALOG_H

#include <QDialog>

class PlatformStyle;

namespace Ui {
class SidechainProposalDialog;
}

class SidechainProposalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SidechainProposalDialog(const PlatformStyle *platformStyle, QWidget *parent = nullptr);
    ~SidechainProposalDialog();

public Q_SLOTS:
    void on_pushButtonCreate_clicked();

    void on_toolButtonKeyHash_clicked();

    void on_toolButtonIDHash1_clicked();

    void on_toolButtonIDHash2_clicked();

    void on_toolButtonSoftwareHashes_clicked();

private:
    Ui::SidechainProposalDialog *ui;

    const PlatformStyle *platformStyle;
};

#endif // SIDECHAINPROPOSALDIALOG_H
