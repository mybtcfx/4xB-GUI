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

#include <QDir>
#include <QJsonObject>
#include <QMap>
#include <QReadWriteLock>
#include <QSet>

#include "INodeAdapter.h"

namespace WalletGui {

class CommandLineParser;
class Style;

class ISettingsObserver {
public:
  virtual ~ISettingsObserver() {}
  virtual void settingsUpdated() = 0;
};

class Settings {
  Q_DISABLE_COPY(Settings)

public:
  static Settings& instance();

  bool hasDebugOption() const;
  bool hasAllowLocalIpOption() const;
  bool hasHideMyPortOption() const;
  bool isEncrypted() const;
  bool isMiningOnLockedScreenEnabled(bool _defaultValue) const;
  bool isSystemTrayAvailable() const;
  bool isRunMinimizedEnabled() const;
  bool isStartOnLoginEnabled() const;
  bool isTestnet() const;
  quintptr getStyleCount() const;
  const Style& getStyle(quintptr _styleIndex) const;
  const Style& getCurrentStyle() const;
  QDir getDataDir() const;
  QString getLegacyAddressBookFile() const;
  QString getCurrentTheme() const;
  QString getMiningPoolSwitchStrategy(const QString& _defaultValue) const;
  QString getP2pBindIp() const;
  QString getVersion() const;
  QString getWalletFile() const;
  quint16 getLocalRpcPort() const;
  quint16 getP2pBindPort() const;
  quint16 getP2pExternalPort() const;
  quint32 getMiningCpuCoreCount(quint32 _defaultValue) const;
  QStringList getExclusiveNodes() const;
  QStringList getMiningPoolList() const;
  QStringList getPeers() const;
  QStringList getPriorityNodes() const;
  QStringList getRecentWalletList() const;
  QStringList getSeedNodes() const;
  QUrl getRemoteRpcUrl() const;
  ConnectionMethod getConnectionMethod() const;

  bool isOptimizationEnabled() const;
  bool isFusionTransactionsVisible() const;
  bool isOptimizationTimeSetManually() const;
  QTime getOptimizationStartTime() const;
  QTime getOptimizationStopTime() const;
  quint64 getOptimizationInterval() const;
  quint64 getOptimizationThreshold() const;
  quint64 getOptimizationMixin() const;

  bool isNewsEnabled() const;

  bool isMinimizeToTrayEnabled() const;
  bool isCloseToTrayEnabled() const;

  void init();
  void restoreDefaultPoolList();
  void setCommandLineParser(CommandLineParser* _cmdLineParser);
  void setConnectionMethod(ConnectionMethod _connectionMethod);
  void setLocalRpcPort(quint16 _port);
  void setRemoteRpcUrl(const QUrl& _url);
  void setP2pBindPort(quint16 _p2pBindPort);
  void setWalletFile(const QString& _file);
  void setCurrentTheme(const QString& _theme);
  void setRecentWalletList(const QStringList& _recentWalletList);
  void setMiningCpuCoreCount(quint32 _cpuCoreCount);
  void setMiningOnLockedScreenEnabled(bool _enable);
  void setMiningPoolList(const QStringList& _miningPoolList);
  void setMiningPoolSwitchStrategy(const QString& _miningPoolSwitchStrategy);
  void setStartOnLoginEnabled(bool _enable);

  void setOptimizationEnabled(bool _enable);
  void setFusionTransactionsVisible(bool _visible);
  void setOptimizationTimeSetManually(bool _enable);
  void setOptimizationStartTime(const QTime& _startTime);
  void setOptimizationStopTime(const QTime& _stopTime);
  void setOptimizationInterval(quint64 _interval);
  void setOptimizationThreshold(quint64 _threshold);
  void setOptimizationMixin(quint64 _mixin);
  void setNewsEnabled(bool _enable);
  void setMinimizeToTrayEnabled(bool _enable);
  void setCloseToTrayEnabled(bool _enable);

  void addObserver(ISettingsObserver* _settingsObserver);
  void removeObserver(ISettingsObserver* _settingsObserver);

#ifdef Q_OS_WIN
  void setUrlHandler();
#endif

private:
  QJsonObject m_settings;
  QStringList m_defaultPoolList;
  quint16 m_p2pBindPort;
  CommandLineParser* m_cmdLineParser;
  mutable QReadWriteLock m_lock;
  QMap<QString, Style*> m_styles;
  QSet<ISettingsObserver*> m_observers;

  Settings();
  ~Settings();

  void saveSettings() const;
  void notifyObservers();
};

}
