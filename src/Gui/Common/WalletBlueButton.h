/*
 * Copyright (c) 2017-2018, The 4xbitcoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of 4xbitcoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <QPushButton>

namespace WalletGui {

class WalletBlueButton : public QPushButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletBlueButton)

public:
  explicit WalletBlueButton(QWidget* _parent);
  virtual ~WalletBlueButton();
};

class WalletNormalBlueButton : public WalletBlueButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletNormalBlueButton)

public:
  explicit WalletNormalBlueButton(QWidget* _parent);
  ~WalletNormalBlueButton();
};

class WalletLargeBlueButton : public WalletBlueButton {
  Q_OBJECT
  Q_DISABLE_COPY(WalletLargeBlueButton)

public:
  explicit WalletLargeBlueButton(QWidget* _parent);
  ~WalletLargeBlueButton();
};

}
