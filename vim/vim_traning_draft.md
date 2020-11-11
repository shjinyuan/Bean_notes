# vim_traning_draft.md
- Maintainer: yuan <eric@email.com>
-    Created: 2020-10-14
- LastChange: 2020-10-14
-    Version: v0.0.01

## syntax

e.g operation + noun
d(elete)
w(word)
type "dw" continuioustypely

### actions in vim
	- d(elete)
	- c(hange)
	- y(ank) means copy
	- p(aste)
	- u(ndo)
	- v(isual select)
	- > means indent to right
	- < means indent to left

	- ds (tDelete Surrounding)
	- cs (Change Surrounding)

### nouns in vim
#### motion
	- w (forward by a "word")
	- b(ack by a "word")
	- 2j => down 2 lines
#### text objects
	- iw means "inner word"
	- i" means "inner quotes"
	- ip means "inner paragraph"
	- as means "a sentence"
	- it means "inner tag for HTML"
#### parameterized text objects(search the postion)
	- f,F
	- t,T
	- \

#### relativenumber
:set relativenumber
:set norelativenumber



## repeat last action
```
## just type dot , any question? yes, just type "."
.

```


### Reference:
[Master the Vim Language](https://www.youtube.com/watch?v=wlR5gYd6um0)

### Book
	- Modern Vim: Craft Your Development Environment with Vim 8 and Neovim

## plugin

#### sourround

``` shell
cs"<  # 成对替换双引号成尖括号
```

