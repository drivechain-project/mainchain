// Copyright (c) 2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECHAINPAGE_H
#define SIDECHAINPAGE_H

#include <QString>
#include <QWidget>

#include <amount.h>
#include <sidechain.h>
#include <uint256.h>

#include <string>

class CBlock;

class PlatformStyle;
class SidechainDepositConfirmationDialog;
class SidechainWithdrawalTableModel;
class SidechainActivationDialog;
class SidechainWTPrimeDialog;
class WalletModel;
class ClientModel;

QT_BEGIN_NAMESPACE
class QTimer;
QT_END_NAMESPACE

namespace Ui {
class SidechainPage;
}

// Sidechain icons
static const std::vector<QString> vSidechainIcons =
{{
    {":/icons/sidechain_one"},
    {":/icons/sidechain_payments"},
}};

class SidechainPage : public QWidget
{
    Q_OBJECT

public:
    explicit SidechainPage(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~SidechainPage();

    void setClientModel(ClientModel *model);

    void setWalletModel(WalletModel *model);

    void setWithdrawalModel(SidechainWithdrawalTableModel *model);

    QString GetSidechainIconPath(uint8_t nSidechain) const;

public Q_SLOTS:
    // TODO make slots that don't need to be public private

    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance,
                    const CAmount& immatureBalance, const CAmount& watchOnlyBalance,
                    const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);

    void on_pushButtonDeposit_clicked();

    void on_pushButtonPaste_clicked();

    void on_pushButtonClear_clicked();

    void on_comboBoxSidechains_currentIndexChanged(const int index);

    void on_listWidgetSidechains_doubleClicked(const QModelIndex& index);

    void on_tableViewWT_doubleClicked(const QModelIndex& index);

    void on_pushButtonAddRemove_clicked();

    void on_pushButtonWTPrimeVote_clicked();

    void on_pushButtonWTDoubleClickHelp_clicked();

    void CheckForSidechainUpdates();

    void gotoWTPage();

    void numBlocksChanged();

    void ShowActivationDialog();

    void ShowWTPrimeDialog();

private:
    Ui::SidechainPage *ui;

    ClientModel *clientModel;
    WalletModel *walletModel;

    SidechainDepositConfirmationDialog *depositConfirmationDialog = nullptr;
    SidechainWithdrawalTableModel *withdrawalModel = nullptr;
    SidechainActivationDialog* activationDialog = nullptr;
    SidechainWTPrimeDialog* wtPrimeDialog = nullptr;

    const PlatformStyle *platformStyle;

    void SetupSidechainList(const std::vector<Sidechain>& vSidechain);

    bool validateDepositAmount();
    bool validateFeeAmount();

    // The sidechains that are currently cached for the list widget
    std::vector<Sidechain> vSidechainCache;
};

QString FormatSidechainNameWithNumber(const QString& strSidechain, int nSidechain);

#endif // SIDECHAINPAGE_H
