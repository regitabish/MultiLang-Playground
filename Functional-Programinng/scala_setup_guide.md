# Scala 環境設定手順 (WSL on Windows 11)

## 環境条件
- Windows 11
- WSL (Windows Subsystem for Linux)
- `javac` は既にインストール済み

## ステップ1: sbtのダウンロードとインストール

1. **Coursierを使用してsbtをインストールするためのコマンドを実行します。**
   以下からsbtをダウンロード
   https://www.scala-sbt.org/download/

2. **ダウンロードが正しく行われたか確認します。**  
   Coursierのヘルプを表示するために、以下のコマンドを実行します。

   ```bash
   cs --help
   ```

   このコマンドが正常に実行され、コマンドのヘルプが表示される場合は、正しくダウンロードされています。もし、以下のようなエラーメッセージが表示された場合:

   ```
   Command 'cs' not found, but can be installed with:
   ```

   PATHにCoursierが追加する必要がある。

3. **PATHにCoursierを追加するコマンド**  
   CoursierをPATHに追加するには、以下のコマンドを実行します。

   ```bash
   echo 'export PATH="$HOME/.local/share/coursier/bin:$PATH"' >> ~/.bashrc
   source ~/.bashrc
   ```

   これにより、ターミナルを再起動した際にもPATHが維持されます。

## ステップ2: Scalaプロジェクトの作成

1. **新しいプロジェクトを作成します。**  
   以下のコマンドを実行して、Scalaプロジェクトを作成します。

   ```bash
   sbt new scala/scala3.g8
   ```

2. **プロジェクトディレクトリに移動します。**

   ```bash
   cd <your_project_name>
   ```

3. **プロジェクトをビルドします。**

   ```bash
   sbt compile
   ```

## ステップ3: Scalaファイルの作成と使用

1. **練習問題として解いたScalaファイルを`src/main/scala`ディレクトリに作成します。**  
   例えば、`11-1-1.scala`のようなファイル名で保存します。これにより、`Main.scala`と同じ場所にファイルが置かれます。
 <pre>  
.
└── src
    └── main
        └── scala
            ├── 11-1-1.scala
            └── Main.scala
 </pre>
2. **Scala REPLを起動します。**

   ```bash
   scala
   ```

3. **ScalaファイルをREPLで実行するために、以下のコマンドを使用します。**

   ```scala
   :load src/main/scala/11-1-1.scala
   ```

## ステップ4: REPLから退出

- REPLを終了するには、以下のいずれかを使用します。
   - `Ctrl + D`（Unix系システムの場合）
   - `Ctrl + Z`（Windowsの場合）を押して、`Enter`を押します。
   - `System.exit(0)`を実行します。

## 注意事項
- Scalaの文法に関するエラーが出た場合は、コードを再確認してください。
- Coursierやsbtのダウンロードが正しく行われているか、常に確認してください。
