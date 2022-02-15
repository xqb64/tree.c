# tree.c

A minimal tree(1) implementation in C.

```
❯ ./a.out .
┣━ README.md
┣━ a.out
┣━ src
┃ ┗━ main.c
┣━ .git
┃ ┣━ index
┃ ┣━ branches
┃ ┣━ objects
┃ ┃ ┣━ 47
┃ ┃ ┃ ┗━ 477070cb2dfcfe08ceff3f12b8bc78457df1bf
┃ ┃ ┣━ a0
┃ ┃ ┃ ┗━ a45dc7aeb5abad65b660c2a072b5bc996de377
┃ ┃ ┣━ 83
┃ ┃ ┃ ┗━ 060650cde2093a69e88d0fb90d1824f30b3e95
┃ ┃ ┣━ 21
┃ ┃ ┃ ┗━ 0b582eca73212f0d192e4245f594e4df3ace2a
┃ ┃ ┣━ c2
┃ ┃ ┃ ┣━ 23ca6f01344b0fc345f6849e69da10c5d09fe2
┃ ┃ ┃ ┗━ cbdd9c16358cfdb95f3a308f085503eed5c354
┃ ┃ ┣━ 92
┃ ┃ ┃ ┗━ d630e881e8e80f315c7bd5ae46d6c781f012c8
┃ ┃ ┣━ 37
┃ ┃ ┃ ┗━ 32583361e52bbd6f86c76ab8ee57c2bed20946
┃ ┃ ┣━ f8
┃ ┃ ┃ ┗━ 305e747aa9833c9c18f69f80a2f0349b69398e
┃ ┃ ┣━ 10
┃ ┃ ┃ ┗━ 9efd805a469cda9f353724e0bb110654311e8b
┃ ┃ ┣━ b7
┃ ┃ ┃ ┗━ b801b869515a00cef2b9ef22222e11a6cec518
┃ ┃ ┣━ 27
┃ ┃ ┃ ┗━ 8728b9916620704fc119db745b918c60a64d68
┃ ┃ ┣━ 30
┃ ┃ ┃ ┗━ b8db9b2897948c861d7386f1baba7c8d4ce434
┃ ┃ ┣━ b1
┃ ┃ ┃ ┗━ b6c4f6ca38813c601db24662757313a385b270
┃ ┃ ┣━ 5f
┃ ┃ ┃ ┗━ 258323f1b6d253a777d06e3c04ad64de3a4fca
┃ ┃ ┣━ fa
┃ ┃ ┃ ┗━ acae0e04d158baf5356aa964f79accc3503fcd
┃ ┃ ┣━ 74
┃ ┃ ┃ ┗━ a58bd85ae36488ae67198bf2e1f666699d2326
┃ ┃ ┣━ c4
┃ ┃ ┃ ┗━ a39d72f5133ac8f1662c08c3961ee1c8b7c1e1
┃ ┃ ┣━ 4d
┃ ┃ ┃ ┗━ bd58a212e1a918d67ab57a70efa792d8453b3c
┃ ┃ ┣━ eb
┃ ┃ ┃ ┗━ 7b5992600ffe2f91c9aec9b7e0ab9825408730
┃ ┃ ┣━ info
┃ ┃ ┣━ pack
┃ ┃ ┣━ 50
┃ ┃ ┃ ┗━ bc3c5c4e1b9226491a8d8575852fe452c9f949
┃ ┃ ┣━ 56
┃ ┃ ┃ ┗━ 548962f2d033650b1c7d7631211c2595933664
┃ ┃ ┗━ fb
┃ ┃   ┗━ f049dc656e217e559651a67a694337c6a01b65
┃ ┣━ logs
┃ ┃ ┣━ refs
┃ ┃ ┃ ┣━ remotes
┃ ┃ ┃ ┃ ┗━ origin
┃ ┃ ┃ ┃   ┗━ master
┃ ┃ ┃ ┗━ heads
┃ ┃ ┃   ┗━ master
┃ ┃ ┗━ HEAD
┃ ┣━ description
┃ ┣━ refs
┃ ┃ ┣━ remotes
┃ ┃ ┃ ┗━ origin
┃ ┃ ┃   ┗━ master
┃ ┃ ┣━ heads
┃ ┃ ┃ ┗━ master
┃ ┃ ┗━ tags
┃ ┣━ COMMIT_EDITMSG
┃ ┣━ config
┃ ┣━ HEAD
┃ ┣━ info
┃ ┃ ┗━ exclude
┃ ┗━ hooks
┃   ┣━ update.sample
┃   ┣━ pre-commit.sample
┃   ┣━ commit-msg.sample
┃   ┣━ push-to-checkout.sample
┃   ┣━ applypatch-msg.sample
┃   ┣━ post-update.sample
┃   ┣━ fsmonitor-watchman.sample
┃   ┣━ pre-receive.sample
┃   ┣━ pre-rebase.sample
┃   ┣━ pre-applypatch.sample
┃   ┣━ pre-push.sample
┃   ┣━ prepare-commit-msg.sample
┃   ┗━ pre-merge-commit.sample
┣━ .gitignore
┗━ LICENSE
```