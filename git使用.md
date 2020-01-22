# 记录使用git的过程中遇见的问题及解决方案

## 1 git当前分支尚未配置上游分支,导致无法push

```shell
提示：更新被拒绝，因为您当前分支的最新提交落后于其对应的远程分支。
提示：再次推送前，先与远程变更合并（如 'git pull ...'）。
详见提示：'git push --help' 中的 'Note about fast-forwards' 小节。
```

引起这个问题是远程仓库和本地不同步引起的

先使用了如下方式，**无效**

```shell
git remote add origin https://github.com/***/
git fetch origin //获取远程更新
git merge origin/master //把更新的内容合并到本地分支
```

然后使用如下**解决方式**，添加上游

```shell
git branch --set-upstream-to=origin/master master
```

## 2 git clone的文件夹与想要的文件夹不是同一级，而是一个父文件夹

引起这个问题的的原因是git clone命令，git clone实际上是自动新建了一个git仓库。

如果想获得子文件夹结构，应该按如下顺序：

1. 在本地新建一个文件夹；
2. git init 本地问价夹为一个git仓库；
3. 设置本地文件夹的git远程仓库： ``` git remote add origin https://github.com/***/ ```
4. 使用git pull指令拉取远程内容即可。

或者在父目录中执行git clone命令（如果情况可以的话，当然多数情况下可能不行）