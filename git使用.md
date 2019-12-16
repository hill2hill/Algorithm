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
