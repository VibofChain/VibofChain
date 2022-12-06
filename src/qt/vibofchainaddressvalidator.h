// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020 The VibofChain Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VIBOFCHAIN_QT_VIBOFCHAINADDRESSVALIDATOR_H
#define VIBOFCHAIN_QT_VIBOFCHAINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class VibofChainAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit VibofChainAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** VibofChain address widget validator, checks for a valid vibofchain address.
 */
class VibofChainAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit VibofChainAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // VIBOFCHAIN_QT_VIBOFCHAINADDRESSVALIDATOR_H
