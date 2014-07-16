/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Build Suite.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef TST_BLACKBOX_H
#define TST_BLACKBOX_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <QProcessEnvironment>
#include <QtTest>

class QbsRunParameters
{
public:
    QbsRunParameters()
    {
        init();
    }

    QbsRunParameters(const QString &cmd, const QStringList &args = QStringList())
        : command(cmd), arguments(args)
    {
        init();
    }

    QbsRunParameters(const QStringList &args)
        : arguments(args)
    {
        init();
    }

    void init()
    {
        expectFailure = false;
        useProfile = true;
        environment = QProcessEnvironment::systemEnvironment();
    }

    QString command;
    QStringList arguments;
    QProcessEnvironment environment;
    bool expectFailure;
    bool useProfile;
};

class TestBlackbox : public QObject
{
    Q_OBJECT
    const QString testDataDir;
    const QString testSourceDir;
    const QString qbsExecutableFilePath;
    const QString buildProfileName;
    const QString buildDir;
    const QString defaultInstallRoot;
    const QString buildGraphPath;

public:
    TestBlackbox();

protected:
    int runQbs(const QbsRunParameters &params = QbsRunParameters());
    void rmDirR(const QString &dir);
    void touch(const QString &fn);
    static void waitForNewTimestamp();
    static QByteArray unifiedLineEndings(const QByteArray &ba);
    static void sanitizeOutput(QByteArray *ba);

public slots:
    void initTestCase();

private slots:
    void addedFilePersistent();
    void addQObjectMacroToCppFile();
    void baseProperties();
    void buildDirectories();
    void build_project_data();
    void build_project();
    void build_project_dry_run_data();
    void build_project_dry_run();
    void changeDependentLib();
    void changedFiles();
    void dependenciesProperty();
    void disabledProduct();
    void disabledProject();
    void disableProduct();
    void duplicateProductNames();
    void duplicateProductNames_data();
    void dynamicLibs();
    void dynamicRuleOutputs();
    void emptyFileTagList();
    void emptySubmodulesList();
    void erroneousFiles_data();
    void erroneousFiles();
    void explicitlyDependsOn();
    void fileDependencies();
    void jsExtensionsFile();
    void jsExtensionsFileInfo();
    void jsExtensionsProcess();
    void jsExtensionsPropertyList();
    void jsExtensionsTextFile();
    void inheritQbsSearchPaths();
    void mocCppIncluded();
    void nonBrokenFilesInBrokenProduct();
    void objC();
    void qmlDebugging();
    void projectWithPropertiesItem();
    void properQuoting();
    void propertiesBlocks();
    void radAfterIncompleteBuild_data();
    void radAfterIncompleteBuild();
    void resolve_project_data();
    void resolve_project();
    void resolve_project_dry_run_data();
    void resolve_project_dry_run();
    void typeChange();
    void usingsAsSoleInputsNonMultiplexed();
    void clean();
    void exportSimple();
    void exportWithRecursiveDepends();
    void fileTagger();
    void rc();
    void renameProduct();
    void renameTargetArtifact();
    void softDependency();
    void subProjects();
    void track_qrc();
    void track_qobject_change();
    void trackAddFile();
    void trackExternalProductChanges();
    void trackRemoveFile();
    void trackAddFileTag();
    void trackRemoveFileTag();
    void trackAddMocInclude();
    void trackAddProduct();
    void trackRemoveProduct();
    void transformers();
    void uic();
    void wildcardRenaming();
    void recursiveRenaming();
    void recursiveWildcards();
    void ruleConditions();
    void ruleCycle();
    void trackAddQObjectHeader();
    void trackRemoveQObjectHeader();
    void overrideProjectProperties();
    void productProperties();
    void propertyChanges();
    void installedApp();
    void toolLookup();
    void checkProjectFilePath();
    void missingProfile();
    void testAssembly();
    void testNsis();
    void testEmbedInfoPlist();
    void testWiX();
    void testNodeJs();
    void testTypeScript();

private:
    QString uniqueProductName(const QString &productName) const;
    QString productBuildDir(const QString &productName) const;
    QString executableFilePath(const QString &productName) const;

    QByteArray m_qbsStderr;
    QByteArray m_qbsStdout;
};

#endif // TST_BLACKBOX_H
