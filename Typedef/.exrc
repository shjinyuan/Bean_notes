if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <expr> <C-X><C-O> omni#cpp#maycomplete#Complete()
imap <C-G>S <Plug>ISurround
imap <C-G>s <Plug>Isurround
imap <C-S> <Plug>Isurround
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
inoremap <silent> <expr> <Plug>(asyncomplete_force_refresh) asyncomplete#force_refresh()
inoremap <silent> <Plug>NERDCommenterInsert  <BS>:call NERDComment('i', 'insert')
inoremap <C-L> l
inoremap <C-K> k
inoremap <C-J> j
inoremap <C-Bslash>c :CtrlSFToggle
nnoremap <silent>  :ZoomToggle
snoremap <silent>  "_c
tnoremap  h
nnoremap  h
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippet()
tnoremap <NL> j
nnoremap <NL> j
tnoremap  k
nnoremap  k
tnoremap  l
nnoremap  l
xnoremap <silent>  :call multiple_cursors#new("v", 0)
nnoremap <silent>  :call multiple_cursors#new("n", 1)
nnoremap <silent>  :LeaderfFile
nmap f <Plug>CtrlSFPrompt
snoremap  "_c
nmap o <Plug>ZoomWin
nnoremap <silent> w :CCTreeWindowToggle
nnoremap <silent> y :CCTreeWindowSaveCopy
nnoremap <F3> :exe "let g:HlUnderCursor=exists(\"g:HlUnderCursor\")?g:HlUnderCursor*-1+1:1"
nmap <F9> :CCTreeLoadDB cscope.out
nmap <F6> :execute 'vimgrep //gj '.expand('%:p:h').'/*.c '.expand('%:p:h').'/*.h'
nmap <F2> :NERDTreeTabsFind
nnoremap c :CtrlSFToggle
nnoremap o :CtrlSFOpen
nmap p <Plug>CtrlSFPwordPath
nmap n <Plug>CtrlSFCwordPath
vmap f <Plug>CtrlSFVwordExec
nmap  hk :tabnew ~/.vim/my_help/key_map.txt
nmap  hu :tabnew ~/.vim/my_help/ubuntu
nmap  hd :tabnew ~/.vim/my_help/
nmap  hm :tabnew ~/.vim/README.md
nmap  zz o
nmap  cy ggVGy
nmap  ci ggVG=
nmap  cu :set fileencoding=utf-8:noh
nmap  cm :%s/\s\+$//:noh
nmap  cM :%s/\r$//g:noh
nmap  bp :bp
nmap  bn :bn
nmap  bb :b 
nmap  b9 :b9
nmap  b8 :b8
nmap  b7 :b7
nmap  b6 :b6
nmap  b5 :b5
nmap  b4 :b4
nmap  b3 :b3
nmap  b2 :b2
nmap  b1 :b1
nmap  ls :ls
nmap  hr :res 25
nmap  vr :vertical res 99
nmap  wk :res -15
nmap  wj :res +15
nmap  wl :vertical res -30
nmap  wh :vertical res +30
nmap  m2 :Man 2 =expand("<cword>")
nmap  mm :Man =expand("<cword>")
nmap  td :packadd termdebug:Termdebug
nmap  tm :vert terminal
nmap  np :set nopaste
nmap  pa :set paste
nmap  mv :set mouse=v
nmap  ma :set mouse=a
vnoremap  ; :
nnoremap  ; :
nnoremap  qa :qa
nnoremap  wa :wa
nnoremap  wq :wq
nnoremap  jq :q
nnoremap  jw :w
nnoremap  je :e
vnoremap <silent>   :WhichKeyVisual ' '<CR
nnoremap <silent>   :WhichKey ' '
nmap  ut :call UpdateTitle()
nmap  at :call AddTitle()
vnoremap <silent> ,w :SendLineToREPL
nnoremap <silent> ,w :SendCurrentLine
map ,rwp <Plug>RestoreWinPosn
map ,swp <Plug>SaveWinPosn
map ,ds <Plug>DrawItStop
map ,di <Plug>DrawItStart
nnoremap ,dk :DirDiffPrev
nnoremap ,dj :DirDiffNext
nnoremap ,dp :diffput
nnoremap ,dg :diffget
nmap ,ca <Plug>NERDCommenterAltDelims
xmap ,cu <Plug>NERDCommenterUncomment
nmap ,cu <Plug>NERDCommenterUncomment
xmap ,cb <Plug>NERDCommenterAlignBoth
nmap ,cb <Plug>NERDCommenterAlignBoth
xmap ,cl <Plug>NERDCommenterAlignLeft
nmap ,cl <Plug>NERDCommenterAlignLeft
nmap ,cA <Plug>NERDCommenterAppend
xmap ,cy <Plug>NERDCommenterYank
nmap ,cy <Plug>NERDCommenterYank
xmap ,cs <Plug>NERDCommenterSexy
nmap ,cs <Plug>NERDCommenterSexy
xmap ,ci <Plug>NERDCommenterInvert
nmap ,ci <Plug>NERDCommenterInvert
nmap ,c$ <Plug>NERDCommenterToEOL
xmap ,cn <Plug>NERDCommenterNested
nmap ,cn <Plug>NERDCommenterNested
xmap ,cm <Plug>NERDCommenterMinimal
nmap ,cm <Plug>NERDCommenterMinimal
xmap ,c  <Plug>NERDCommenterToggle
nmap ,c  <Plug>NERDCommenterToggle
xmap ,cc <Plug>NERDCommenterComment
nmap ,cc <Plug>NERDCommenterComment
nnoremap ,fx :exe "let g:AutoResizeFocusWindow=exists(\"g:AutoResizeFocusWindow\")?g:AutoResizeFocusWindow*-1+1:1"
nmap ,m :MRU
map ,\ :call ShowFuncName()
nmap ,fd :cs find d 
nmap ,fi :cs find i 
nmap ,ff :cs find f 
nmap ,fe :cs find e 
nmap ,ft :cs find t 
nmap ,fc :cs find c 
nmap ,fg :cs find g 
nmap ,fs :cs find s 
nmap ,vd :vert scs find d =expand("<cword>")
nmap ,vi :vert scs find i =expand("<cfile>")
nmap ,vf :vert scs find f =expand("<cfile>")
nmap ,ve :vert scs find e =expand("<cword>")
nmap ,vt :vert scs find t =expand("<cword>")
nmap ,vc :vert scs find c =expand("<cword>")
nmap ,vg :vert scs find g =expand("<cword>")
nmap ,vs :vert scs find s =expand("<cword>")
nmap ,nq :set cscopequickfix=
nmap ,sq :set cscopequickfix=s+,g+,c+,d+,i+,t+,e+,a+
nmap ,sd :cs find d =expand("<cword>")
nmap ,si :cs find i =expand("<cfile>")
nmap ,sf :cs find f =expand("<cfile>")
nmap ,se :cs find e =expand("<cword>")
nmap ,st :cs find t =expand("<cword>")
nmap ,sc :cs find c =expand("<cword>")
nmap ,sg :cs find g =expand("<cword>")
nmap ,ss :cs find s =expand("<cword>")
nmap ,sa :cs add cscope.out
nmap ,9f :call AutoLoadCTagsAndCScope()
nmap ,f9 :call Generate_fntags_tags_cscope()
nmap ,8f :call LoadTagsByBufferName()
nmap ,f8 :call Generate_cpp_tags_cscope()
nmap ,7f :botright copen 10
nmap ,<F7> :lclose
nmap ,f7 :SyntasticCheck
nmap ,<F6> :vimgrep /=expand("<cword>")/
nmap ,f6 :execute 'vimgrep /'.expand('<cword>').'/gj '.expand('%:p:h').'/*.c '.expand('%:p:h').'/*.h':botright cwindow
nnoremap <silent> ,mkt :AsyncRun -cwd=<VIM_FILEDIR> -raw make test 
nnoremap <silent> ,mkr :AsyncRun -cwd=<VIM_FILEDIR> -raw make run 
nnoremap <silent> ,mkc :AsyncRun -cwd=<VIM_FILEDIR> make clean
nnoremap <silent> ,mk :AsyncRun -cwd=<VIM_FILEDIR> make 
nnoremap <silent> ,Mkt :AsyncRun -cwd=<root> -raw make test 
nnoremap <silent> ,Mkr :AsyncRun -cwd=<root> -raw make run 
nnoremap <silent> ,Mkc :AsyncRun -cwd=<root> make clean
nnoremap <silent> ,Mk :AsyncRun -cwd=<root> make 
nnoremap <silent> ,run :AsyncRun -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" 
nnoremap <silent> ,g++ :AsyncRun g++ -Wall -O2 "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" 
nnoremap <silent> ,gcc :AsyncRun gcc -Wall -O2 "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT)" 
nnoremap ,f5 :call asyncrun#quickfix_toggle(6)
nnoremap ,re :REPLToggle
noremap ,pd :PreviewScroll +1
noremap ,pu :PreviewScroll -1
nmap ,f4 :PreviewTag
nmap ,f3 :exec 'MRU' expand('%:p:h')
nmap ,<F2> :silent! VE .
nmap ,f2 :NERDTreeTabsToggle
nmap ,f1 :TagbarToggle
nmap <silent> ,cd :exe 'cd ' . OpenDir:pwd
map <silent> ,4 :diffget 4:diffupdate
map <silent> ,3 :diffget 3:diffupdate
map <silent> ,2 :diffget 2:diffupdate
map <silent> ,1 :diffget 1:diffupdate
nnoremap ,af :Autoformat
vmap <silent> ,tw <Plug>TranslateWV
nmap <silent> ,tw <Plug>TranslateW
vmap <silent> ,te <Plug>TranslateV
nmap <silent> ,te <Plug>Translate
vnoremap <silent> , :WhichKeyVisual ','<CR
nnoremap <silent> , :WhichKey ','
noremap ,lt :LeaderfTag
noremap ,lb :LeaderfBuffer
noremap ,lf :LeaderfFunction!
noremap ,lm :LeaderfMru
nnoremap ,fr :CtrlSF 
nnoremap - :call bufferhint#Popup()
nnoremap =op <Nop>
xmap S <Plug>VSurround
nmap [xx <Plug>unimpaired_line_xml_encode
xmap [x <Plug>unimpaired_xml_encode
nmap [x <Plug>unimpaired_xml_encode
nmap [uu <Plug>unimpaired_line_url_encode
xmap [u <Plug>unimpaired_url_encode
nmap [u <Plug>unimpaired_url_encode
nmap [yy <Plug>unimpaired_line_string_encode
xmap [y <Plug>unimpaired_string_encode
nmap [y <Plug>unimpaired_string_encode
nmap [P <Plug>unimpairedPutAbove
nmap [p <Plug>unimpairedPutAbove
xmap [e <Plug>unimpairedMoveSelectionUp
nmap [e <Plug>unimpairedMoveUp
nmap [  <Plug>unimpairedBlankUp
omap [n <Plug>unimpairedContextPrevious
xmap [n <Plug>unimpairedContextPrevious
nmap [n <Plug>unimpairedContextPrevious
nmap [f <Plug>unimpairedDirectoryPrevious
nmap [<C-T> <Plug>unimpairedTPPrevious
nmap [ <Plug>unimpairedTPPrevious
nmap [T <Plug>unimpairedTFirst
nmap [t <Plug>unimpairedTPrevious
nmap [<C-Q> <Plug>unimpairedQPFile
nmap [ <Plug>unimpairedQPFile
nmap [Q <Plug>unimpairedQFirst
nmap [q <Plug>unimpairedQPrevious
nmap [<C-L> <Plug>unimpairedLPFile
nmap [ <Plug>unimpairedLPFile
nmap [L <Plug>unimpairedLFirst
nmap [l <Plug>unimpairedLPrevious
nmap [B <Plug>unimpairedBFirst
nmap [b <Plug>unimpairedBPrevious
nmap [A <Plug>unimpairedAFirst
nmap [a <Plug>unimpairedAPrevious
nnoremap \ :call bufferhint#LoadPrevious()
nmap ]xx <Plug>unimpaired_line_xml_decode
xmap ]x <Plug>unimpaired_xml_decode
nmap ]x <Plug>unimpaired_xml_decode
nmap ]uu <Plug>unimpaired_line_url_decode
xmap ]u <Plug>unimpaired_url_decode
nmap ]u <Plug>unimpaired_url_decode
nmap ]yy <Plug>unimpaired_line_string_decode
xmap ]y <Plug>unimpaired_string_decode
nmap ]y <Plug>unimpaired_string_decode
nmap ]P <Plug>unimpairedPutBelow
nmap ]p <Plug>unimpairedPutBelow
xmap ]e <Plug>unimpairedMoveSelectionDown
nmap ]e <Plug>unimpairedMoveDown
nmap ]  <Plug>unimpairedBlankDown
omap ]n <Plug>unimpairedContextNext
xmap ]n <Plug>unimpairedContextNext
nmap ]n <Plug>unimpairedContextNext
nmap ]f <Plug>unimpairedDirectoryNext
nmap ]<C-T> <Plug>unimpairedTPNext
nmap ] <Plug>unimpairedTPNext
nmap ]T <Plug>unimpairedTLast
nmap ]t <Plug>unimpairedTNext
nmap ]<C-Q> <Plug>unimpairedQNFile
nmap ] <Plug>unimpairedQNFile
nmap ]Q <Plug>unimpairedQLast
nmap ]q <Plug>unimpairedQNext
nmap ]<C-L> <Plug>unimpairedLNFile
nmap ] <Plug>unimpairedLNFile
nmap ]L <Plug>unimpairedLLast
nmap ]l <Plug>unimpairedLNext
nmap ]B <Plug>unimpairedBLast
nmap ]b <Plug>unimpairedBNext
nmap ]A <Plug>unimpairedALast
nmap ]a <Plug>unimpairedANext
nnoremap cop <Nop>
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap ds <Plug>Dsurround
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xnoremap <silent> g<C-A> :call multiple_cursors#select_all("v", 0)
xnoremap <silent> g :call multiple_cursors#select_all("v", 0)
nnoremap <silent> g<C-A> :call multiple_cursors#select_all("n", 1)
nnoremap <silent> g :call multiple_cursors#select_all("n", 1)
xnoremap <silent> g<M-n> :call multiple_cursors#select_all("v", 0)
xnoremap <silent> gî :call multiple_cursors#select_all("v", 0)
nnoremap <silent> g<M-n> :call multiple_cursors#select_all("n", 0)
nnoremap <silent> gî :call multiple_cursors#select_all("n", 0)
xnoremap <silent> g<C-N> :call multiple_cursors#new("v", 0)
xnoremap <silent> g :call multiple_cursors#new("v", 0)
nnoremap <silent> g<C-N> :call multiple_cursors#new("n", 0)
nnoremap <silent> g :call multiple_cursors#new("n", 0)
xmap gS <Plug>VgSurround
map ta :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
nnoremap <silent> <C-Bslash>w :CCTreeWindowToggle
nnoremap <silent> <C-Bslash>y :CCTreeWindowSaveCopy
nnoremap <SNR>124_: :=v:count ? v:count : ''
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
xnoremap <silent> <C-N> :call multiple_cursors#new("v", 0)
nnoremap <silent> <C-N> :call multiple_cursors#new("n", 1)
nnoremap <silent> <Plug>TranslateX :TranslateX
vnoremap <silent> <Plug>TranslateRV :TranslateR
nnoremap <silent> <Plug>TranslateR :TranslateR
vnoremap <silent> <Plug>TranslateWV :TranslateW
nnoremap <silent> <Plug>TranslateW :TranslateW
vnoremap <silent> <Plug>TranslateV :Translate
nnoremap <silent> <Plug>Translate :Translate
nmap <silent> <Plug>RestoreWinPosn :call RestoreWinPosn()
nmap <silent> <Plug>SaveWinPosn :call SaveWinPosn()
noremap <silent> <Plug>DrawItStop :set lz:call DrawIt#DrawItStop():set nolz
noremap <silent> <Plug>DrawItStart :set lz:call DrawIt#DrawItStart():set nolz
nnoremap <silent> <Plug>unimpairedTPNext :exe "p".(v:count ? v:count : "")."tnext"
nnoremap <silent> <Plug>unimpairedTPPrevious :exe "p".(v:count ? v:count : "")."tprevious"
nnoremap <silent> <Plug>unimpairedTLast :exe "".(v:count ? v:count : "")."tlast"
nnoremap <silent> <Plug>unimpairedTFirst :exe "".(v:count ? v:count : "")."tfirst"
nnoremap <silent> <Plug>unimpairedTNext :exe "".(v:count ? v:count : "")."tnext"
nnoremap <silent> <Plug>unimpairedTPrevious :exe "".(v:count ? v:count : "")."tprevious"
nnoremap <silent> <Plug>unimpairedQNFile :exe "".(v:count ? v:count : "")."cnfile"zv
nnoremap <silent> <Plug>unimpairedQPFile :exe "".(v:count ? v:count : "")."cpfile"zv
nnoremap <silent> <Plug>unimpairedQLast :exe "".(v:count ? v:count : "")."clast"zv
nnoremap <silent> <Plug>unimpairedQFirst :exe "".(v:count ? v:count : "")."cfirst"zv
nnoremap <silent> <Plug>unimpairedQNext :exe "".(v:count ? v:count : "")."cnext"zv
nnoremap <silent> <Plug>unimpairedQPrevious :exe "".(v:count ? v:count : "")."cprevious"zv
nnoremap <silent> <Plug>unimpairedLNFile :exe "".(v:count ? v:count : "")."lnfile"zv
nnoremap <silent> <Plug>unimpairedLPFile :exe "".(v:count ? v:count : "")."lpfile"zv
nnoremap <silent> <Plug>unimpairedLLast :exe "".(v:count ? v:count : "")."llast"zv
nnoremap <silent> <Plug>unimpairedLFirst :exe "".(v:count ? v:count : "")."lfirst"zv
nnoremap <silent> <Plug>unimpairedLNext :exe "".(v:count ? v:count : "")."lnext"zv
nnoremap <silent> <Plug>unimpairedLPrevious :exe "".(v:count ? v:count : "")."lprevious"zv
nnoremap <silent> <Plug>unimpairedBLast :exe "".(v:count ? v:count : "")."blast"
nnoremap <silent> <Plug>unimpairedBFirst :exe "".(v:count ? v:count : "")."bfirst"
nnoremap <silent> <Plug>unimpairedBNext :exe "".(v:count ? v:count : "")."bnext"
nnoremap <silent> <Plug>unimpairedBPrevious :exe "".(v:count ? v:count : "")."bprevious"
nnoremap <silent> <Plug>unimpairedALast :exe "".(v:count ? v:count : "")."last"
nnoremap <silent> <Plug>unimpairedAFirst :exe "".(v:count ? v:count : "")."first"
nnoremap <silent> <Plug>unimpairedANext :exe "".(v:count ? v:count : "")."next"
nnoremap <silent> <Plug>unimpairedAPrevious :exe "".(v:count ? v:count : "")."previous"
nnoremap <silent> <Plug>SurroundRepeat .
nmap <C-W>o <Plug>ZoomWin
nnoremap <silent> <Plug>GitGutterPreviewHunk :call gitgutter#utility#warn('please change your map <Plug>GitGutterPreviewHunk to <Plug>(GitGutterPreviewHunk)')
nnoremap <silent> <Plug>(GitGutterPreviewHunk) :GitGutterPreviewHunk
nnoremap <silent> <Plug>GitGutterUndoHunk :call gitgutter#utility#warn('please change your map <Plug>GitGutterUndoHunk to <Plug>(GitGutterUndoHunk)')
nnoremap <silent> <Plug>(GitGutterUndoHunk) :GitGutterUndoHunk
nnoremap <silent> <Plug>GitGutterStageHunk :call gitgutter#utility#warn('please change your map <Plug>GitGutterStageHunk to <Plug>(GitGutterStageHunk)')
nnoremap <silent> <Plug>(GitGutterStageHunk) :GitGutterStageHunk
xnoremap <silent> <Plug>GitGutterStageHunk :call gitgutter#utility#warn('please change your map <Plug>GitGutterStageHunk to <Plug>(GitGutterStageHunk)')
xnoremap <silent> <Plug>(GitGutterStageHunk) :GitGutterStageHunk
nnoremap <silent> <expr> <Plug>GitGutterPrevHunk &diff ? '[c' : ":\call gitgutter#utility#warn('please change your map \<Plug>GitGutterPrevHunk to \<Plug>(GitGutterPrevHunk)')\"
nnoremap <silent> <expr> <Plug>(GitGutterPrevHunk) &diff ? '[c' : ":\execute v:count1 . 'GitGutterPrevHunk'\"
nnoremap <silent> <expr> <Plug>GitGutterNextHunk &diff ? ']c' : ":\call gitgutter#utility#warn('please change your map \<Plug>GitGutterNextHunk to \<Plug>(GitGutterNextHunk)')\"
nnoremap <silent> <expr> <Plug>(GitGutterNextHunk) &diff ? ']c' : ":\execute v:count1 . 'GitGutterNextHunk'\"
xnoremap <silent> <Plug>(GitGutterTextObjectOuterVisual) :call gitgutter#hunk#text_object(0)
xnoremap <silent> <Plug>(GitGutterTextObjectInnerVisual) :call gitgutter#hunk#text_object(1)
onoremap <silent> <Plug>(GitGutterTextObjectOuterPending) :call gitgutter#hunk#text_object(0)
onoremap <silent> <Plug>(GitGutterTextObjectInnerPending) :call gitgutter#hunk#text_object(1)
nnoremap <silent> <M-n> :LeaderfBuffer
nnoremap <silent> <C-P> :LeaderfFile
vnoremap <silent> <Plug>LeaderfGtagsGrep :=leaderf#Gtags#startCmdline(2, 1, 'g')
vnoremap <silent> <Plug>LeaderfGtagsSymbol :=leaderf#Gtags#startCmdline(2, 1, 's')
vnoremap <silent> <Plug>LeaderfGtagsReference :=leaderf#Gtags#startCmdline(2, 1, 'r')
vnoremap <silent> <Plug>LeaderfGtagsDefinition :=leaderf#Gtags#startCmdline(2, 1, 'd')
nnoremap <Plug>LeaderfGtagsGrep :=leaderf#Gtags#startCmdline(0, 1, 'g')
onoremap <Plug>LeaderfGtagsGrep :=leaderf#Gtags#startCmdline(0, 1, 'g')
nnoremap <Plug>LeaderfGtagsSymbol :=leaderf#Gtags#startCmdline(0, 1, 's')
onoremap <Plug>LeaderfGtagsSymbol :=leaderf#Gtags#startCmdline(0, 1, 's')
nnoremap <Plug>LeaderfGtagsReference :=leaderf#Gtags#startCmdline(0, 1, 'r')
onoremap <Plug>LeaderfGtagsReference :=leaderf#Gtags#startCmdline(0, 1, 'r')
nnoremap <Plug>LeaderfGtagsDefinition :=leaderf#Gtags#startCmdline(0, 1, 'd')
onoremap <Plug>LeaderfGtagsDefinition :=leaderf#Gtags#startCmdline(0, 1, 'd')
vnoremap <silent> <Plug>LeaderfRgBangVisualRegexBoundary :=leaderf#Rg#startCmdline(2, 1, 1, 1)
vnoremap <silent> <Plug>LeaderfRgBangVisualRegexNoBoundary :=leaderf#Rg#startCmdline(2, 1, 1, 0)
vnoremap <silent> <Plug>LeaderfRgBangVisualLiteralBoundary :=leaderf#Rg#startCmdline(2, 1, 0, 1)
vnoremap <silent> <Plug>LeaderfRgBangVisualLiteralNoBoundary :=leaderf#Rg#startCmdline(2, 1, 0, 0)
vnoremap <silent> <Plug>LeaderfRgVisualRegexBoundary :=leaderf#Rg#startCmdline(2, 0, 1, 1)
vnoremap <silent> <Plug>LeaderfRgVisualRegexNoBoundary :=leaderf#Rg#startCmdline(2, 0, 1, 0)
vnoremap <silent> <Plug>LeaderfRgVisualLiteralBoundary :=leaderf#Rg#startCmdline(2, 0, 0, 1)
vnoremap <silent> <Plug>LeaderfRgVisualLiteralNoBoundary :=leaderf#Rg#startCmdline(2, 0, 0, 0)
noremap <Plug>LeaderfRgWORDRegexBoundary :=leaderf#Rg#startCmdline(1, 0, 1, 1)
noremap <Plug>LeaderfRgWORDRegexNoBoundary :=leaderf#Rg#startCmdline(1, 0, 1, 0)
noremap <Plug>LeaderfRgWORDLiteralBoundary :=leaderf#Rg#startCmdline(1, 0, 0, 1)
noremap <Plug>LeaderfRgWORDLiteralNoBoundary :=leaderf#Rg#startCmdline(1, 0, 0, 0)
noremap <Plug>LeaderfRgBangCwordRegexBoundary :=leaderf#Rg#startCmdline(0, 1, 1, 1)
noremap <Plug>LeaderfRgBangCwordRegexNoBoundary :=leaderf#Rg#startCmdline(0, 1, 1, 0)
noremap <Plug>LeaderfRgBangCwordLiteralBoundary :=leaderf#Rg#startCmdline(0, 1, 0, 1)
noremap <Plug>LeaderfRgBangCwordLiteralNoBoundary :=leaderf#Rg#startCmdline(0, 1, 0, 0)
noremap <Plug>LeaderfRgCwordRegexBoundary :=leaderf#Rg#startCmdline(0, 0, 1, 1)
noremap <Plug>LeaderfRgCwordRegexNoBoundary :=leaderf#Rg#startCmdline(0, 0, 1, 0)
noremap <Plug>LeaderfRgCwordLiteralBoundary :=leaderf#Rg#startCmdline(0, 0, 0, 1)
noremap <Plug>LeaderfRgCwordLiteralNoBoundary :=leaderf#Rg#startCmdline(0, 0, 0, 0)
noremap <Plug>LeaderfRgPrompt :Leaderf rg -e 
noremap <silent> <Plug>LeaderfMruCwdFullScreen :Leaderf mru --fullScreen
noremap <silent> <Plug>LeaderfMruCwdRight :Leaderf mru --right
noremap <silent> <Plug>LeaderfMruCwdLeft :Leaderf mru --left
noremap <silent> <Plug>LeaderfMruCwdBottom :Leaderf mru --bottom
noremap <silent> <Plug>LeaderfMruCwdTop :Leaderf mru --top
noremap <silent> <Plug>LeaderfBufferFullScreen :Leaderf buffer --fullScreen
noremap <silent> <Plug>LeaderfBufferRight :Leaderf buffer --right
noremap <silent> <Plug>LeaderfBufferLeft :Leaderf buffer --left
noremap <silent> <Plug>LeaderfBufferBottom :Leaderf buffer --bottom
noremap <silent> <Plug>LeaderfBufferTop :Leaderf buffer --top
noremap <silent> <Plug>LeaderfFileFullScreen :Leaderf file --fullScreen
noremap <silent> <Plug>LeaderfFileRight :Leaderf file --right
noremap <silent> <Plug>LeaderfFileLeft :Leaderf file --left
noremap <silent> <Plug>LeaderfFileBottom :Leaderf file --bottom
noremap <silent> <Plug>LeaderfFileTop :Leaderf file --top
xnoremap <silent> <Plug>(openbrowser-smart-search) :call openbrowser#_keymap_smart_search('v')
nnoremap <silent> <Plug>(openbrowser-smart-search) :call openbrowser#_keymap_smart_search('n')
xnoremap <silent> <Plug>(openbrowser-search) :call openbrowser#_keymap_search('v')
nnoremap <silent> <Plug>(openbrowser-search) :call openbrowser#_keymap_search('n')
xnoremap <silent> <Plug>(openbrowser-open-incognito) :call openbrowser#_keymap_open('v', 0, ['--incognito'])
nnoremap <silent> <Plug>(openbrowser-open-incognito) :call openbrowser#_keymap_open('n', 0, ['--incognito'])
xnoremap <silent> <Plug>(openbrowser-open) :call openbrowser#_keymap_open('v')
nnoremap <silent> <Plug>(openbrowser-open) :call openbrowser#_keymap_open('n')
nnoremap <Plug>CtrlSFQuickfixPrompt :CtrlSFQuickfix 
nnoremap <Plug>CtrlSFPrompt :CtrlSF 
snoremap <C-R> "_c
snoremap <silent> <C-H> "_c
snoremap <silent> <Del> "_c
snoremap <silent> <BS> "_c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
nnoremap <Plug>(lsp-signature-help) :call lsp#ui#vim#signature_help#get_signature_help_under_cursor()
nnoremap <Plug>(lsp-previous-reference) :call lsp#ui#vim#references#jump(-1)
nnoremap <Plug>(lsp-next-reference) :call lsp#ui#vim#references#jump(+1)
nnoremap <Plug>(lsp-status) :echo lsp#get_server_status()
nnoremap <Plug>(lsp-peek-implementation) :call lsp#ui#vim#implementation(1)
nnoremap <Plug>(lsp-implementation) :call lsp#ui#vim#implementation(0)
xnoremap <Plug>(lsp-document-range-format) :<Home>silent <End>call lsp#ui#vim#document_range_format()
nnoremap <Plug>(lsp-document-range-format) :set opfunc=lsp#ui#vim#document_range_format_opfuncg@
vnoremap <Plug>(lsp-document-format) :<Home>silent <End>call lsp#ui#vim#document_range_format()
nnoremap <Plug>(lsp-document-format) :call lsp#ui#vim#document_format()
nnoremap <Plug>(lsp-workspace-symbol) :call lsp#ui#vim#workspace_symbol()
nnoremap <Plug>(lsp-peek-type-definition) :call lsp#ui#vim#type_definition(1)
nnoremap <Plug>(lsp-type-hierarchy) :call lsp#ui#vim#type_hierarchy()
nnoremap <Plug>(lsp-type-definition) :call lsp#ui#vim#type_definition(0)
nnoremap <Plug>(lsp-rename) :call lsp#ui#vim#rename()
nnoremap <Plug>(lsp-references) :call lsp#ui#vim#references()
nnoremap <Plug>(lsp-previous-diagnostic-nowrap) :call lsp#ui#vim#diagnostics#previous_diagnostic("--nowrap")
nnoremap <Plug>(lsp-previous-diagnostic) :call lsp#ui#vim#diagnostics#previous_diagnostic()
nnoremap <Plug>(lsp-next-diagnostic-nowrap) :call lsp#ui#vim#diagnostics#next_diagnostic("--nowrap")
nnoremap <Plug>(lsp-next-diagnostic) :call lsp#ui#vim#diagnostics#next_diagnostic()
nnoremap <Plug>(lsp-previous-warning-nowrap) :call lsp#ui#vim#diagnostics#previous_warning("--nowrap")
nnoremap <Plug>(lsp-previous-warning) :call lsp#ui#vim#diagnostics#previous_warning()
nnoremap <Plug>(lsp-next-warning-nowrap) :call lsp#ui#vim#diagnostics#next_warning("--nowrap")
nnoremap <Plug>(lsp-next-warning) :call lsp#ui#vim#diagnostics#next_warning()
nnoremap <Plug>(lsp-previous-error-nowrap) :call lsp#ui#vim#diagnostics#previous_error("--nowrap")
nnoremap <Plug>(lsp-previous-error) :call lsp#ui#vim#diagnostics#previous_error()
nnoremap <Plug>(lsp-next-error-nowrap) :call lsp#ui#vim#diagnostics#next_error("--nowrap")
nnoremap <Plug>(lsp-next-error) :call lsp#ui#vim#diagnostics#next_error()
nnoremap <Plug>(lsp-preview-focus) :call lsp#ui#vim#output#focuspreview()
nnoremap <Plug>(lsp-preview-close) :call lsp#ui#vim#output#closepreview()
nnoremap <Plug>(lsp-hover) :call lsp#ui#vim#hover#get_hover_under_cursor()
nnoremap <Plug>(lsp-document-diagnostics) :call lsp#ui#vim#diagnostics#document_diagnostics()
nnoremap <Plug>(lsp-document-symbol) :call lsp#ui#vim#document_symbol()
nnoremap <Plug>(lsp-peek-definition) :call lsp#ui#vim#definition(1)
nnoremap <Plug>(lsp-definition) :call lsp#ui#vim#definition(0)
nnoremap <Plug>(lsp-peek-declaration) :call lsp#ui#vim#declaration(1)
nnoremap <Plug>(lsp-declaration) :call lsp#ui#vim#declaration(0)
nnoremap <Plug>(lsp-code-action) :call lsp#ui#vim#code_action()
xnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment("x", "Uncomment")
nnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment("n", "Uncomment")
xnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment("x", "AlignBoth")
nnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment("n", "AlignBoth")
xnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment("x", "AlignLeft")
nnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment("n", "AlignLeft")
nnoremap <silent> <Plug>NERDCommenterAppend :call NERDComment("n", "Append")
xnoremap <silent> <Plug>NERDCommenterYank :call NERDComment("x", "Yank")
nnoremap <silent> <Plug>NERDCommenterYank :call NERDComment("n", "Yank")
xnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment("x", "Sexy")
nnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment("n", "Sexy")
xnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment("x", "Invert")
nnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment("n", "Invert")
nnoremap <silent> <Plug>NERDCommenterToEOL :call NERDComment("n", "ToEOL")
xnoremap <silent> <Plug>NERDCommenterNested :call NERDComment("x", "Nested")
nnoremap <silent> <Plug>NERDCommenterNested :call NERDComment("n", "Nested")
xnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment("x", "Minimal")
nnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment("n", "Minimal")
xnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment("x", "Toggle")
nnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment("n", "Toggle")
xnoremap <silent> <Plug>NERDCommenterComment :call NERDComment("x", "Comment")
nnoremap <silent> <Plug>NERDCommenterComment :call NERDComment("n", "Comment")
nnoremap <C-Bslash><F3> :exe "let g:HlUnderCursor=exists(\"g:HlUnderCursor\")?g:HlUnderCursor*-1+1:1"
nmap <C-Bslash><F9> :CCTreeLoadDB cscope.out
nmap <C-F9> :call AutoLoadCTagsAndCScope()
nmap <F9> :call Generate_fntags_tags_cscope()
nmap <C-F7> :Errors
nmap <F7> :SyntasticCheck
nmap <C-Bslash><F6> :execute 'vimgrep //gj '.expand('%:p:h').'/*.c '.expand('%:p:h').'/*.h'
nmap <C-F6> :vimgrep /=expand("<cword>")/ **/*.c **/*.h:botright cwindow
nmap <F6> :execute 'vimgrep /'.expand('<cword>').'/gj '.expand('%:p:h').'/*.c '.expand('%:p:h').'/*.h':botright cwindow
nmap <C-F5> :UndotreeToggle
nmap <F4> :PreviewTag
nmap <F3> :exec 'MRU' expand('%:p:h')
nmap <C-Bslash><F2> :NERDTreeTabsFind
nmap <F2> :NERDTreeTabsToggle
tnoremap <C-L> l
tnoremap <C-K> k
tnoremap <C-J> j
tnoremap <C-H> h
nnoremap <C-L> l
nnoremap <C-K> k
nnoremap <C-J> j
nnoremap <C-H> h
nnoremap <silent> <C-A> :ZoomToggle
nnoremap <C-Bslash>c :CtrlSFToggle
nnoremap <C-Bslash>o :CtrlSFOpen
nmap <C-Bslash>p <Plug>CtrlSFPwordPath
nmap <C-Bslash>n <Plug>CtrlSFCwordPath
nmap <C-P>f <Plug>CtrlSFPrompt
vmap <C-Bslash>f <Plug>CtrlSFVwordExec
noremap <F5> :Autoformat:w
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <silent> 	 =UltiSnips#ExpandSnippet()
inoremap <NL> j
inoremap  k
inoremap  l
imap  <Plug>Isurround
inoremap <expr>  omni#cpp#maycomplete#Complete()
inoremap c :CtrlSFToggle
inoremap " ""i
inoremap ' ''i
inoremap ( ()i
inoremap ,pd :PreviewScroll +1
inoremap ,pu :PreviewScroll -1
cmap ,gk :call Generate_kernel_tags_cscope()
cmap ,pi PlugInstall
cmap ,e 
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap < <>i
inoremap <expr> > omni#cpp#maycomplete#Arrow()
nnoremap <silent> î :LeaderfBuffer
inoremap [ []i
inoremap jj =SkipPair()
inoremap js :w
inoremap jk 
inoremap { {}i
cabbr gitv =(getcmdtype()==':' && getcmdpos()==1 ? 'Gitv' : 'gitv')
abbr xtime =strftime("%Y-%m-%d %H:%M:%S")
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set autoread
set autowrite
set background=dark
set backspace=indent,eol,start
set cindent
set cinoptions=:0,g0,N-s
set clipboard=unnamedplus
set completeopt=menuone,noinsert,noselect
set cscoperelative
set cscopetag
set cscopetagorder=1
set cscopeverbose
set fileencodings=utf-8,gb2312,gbk,gb18030
set helpheight=10
set helplang=cn
set hidden
set history=100
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set mouse=a
set omnifunc=omni#cpp#complete#Main
set pumheight=10
set pyxversion=3
set ruler
set runtimepath=~/.vim,~/.vim/plugged/vim-fugitive/,~/.vim/plugged/vim-markdown/,~/.vim/plugged/nerdcommenter/,~/.vim/plugged/vimtex/,~/.vim/plugged/vim-latex-live-preview/,~/.vim/plugged/async.vim/,~/.vim/plugged/asyncomplete.vim/,~/.vim/plugged/asyncomplete-lsp.vim/,~/.vim/plugged/vim-lsp/,~/.vim/plugged/vim-lsp-settings/,~/.vim/plugged/AutoComplPop/,~/.vim/plugged/OmniCppComplete/,~/.vim/plugged/ultisnips/,~/.vim/plugged/vim-snippets/,~/.vim/plugged/cpp.vim/,~/.vim/plugged/vim-autoformat/,~/.vim/plugged/gitv/,~/.vim/plugged/ctrlsf.vim/,~/.vim/plugged/previm/,~/.vim/plugged/open-browser.vim/,~/.vim/plugged/leaderf/,~/.vim/plugged/bufexplorer/,~/.vim/plugged/bufferhint/,~/.vim/plugged/vim-gitgutter/,~/.vim/plugged/undotree/,~/.vim/plugged/vim-nerdtree-tabs/,~/.vim/plugged/nerdtree-git-plugin/,~/.vim/plugged/vim-airline/,~/.vim/plugged/vim-airline-themes/,~/.vim/plugged/nerdtree/,~/.vim/plugged/mru.vim/,~/.vim/plugged/ZoomWin/,~/.vim/plugged/vim-preview/,~/.vim/plugged/tagbar/,~/.vim/plugged/asyncrun.vim/,~/.vim/plugged/vim-surround/,~/.vim/plugged/CCTree/,~/.vim/plugged/vim-dirdiff/,~/.vim/plugged/vim-unimpaired/,~/.vim/plugged/tablify/,~/.vim/plugged/vim-which-key/,~/.vim/plugged/genutils/,~/.vim/plugged/DrawIt/,~/.vim/plugged/vim-repl/,~/.vim/plugged/vim-translate-me/,~/.vim/plugged/vim-multiple-cursors/,~/.vim/plugged/vim-auto-save/,~/.vim/plugged/DoxygenToolkit.vim/,/usr/local/vim/share/vim/vimfiles,/usr/local/vim/share/vim/vim82,/usr/local/vim/share/vim/vimfiles/after,~/.vim/plugged/vim-markdown/after,~/.vim/plugged/vimtex/after,~/.vim/plugged/OmniCppComplete/after,~/.vim/plugged/ultisnips/after,~/.vim/plugged/ctrlsf.vim/after,~/.vim/after
set scrolloff=2
set shiftwidth=4
set showcmd
set showtabline=2
set smartcase
set smartindent
set splitright
set statusline=[%1*%M%*%-.2n]%.62f%h%r%=[%-4.(%P:%LL,%c]%<%{fugitive#statusline()}[%Y|%{&fenc}]%)
set noswapfile
set tabline=%!airline#extensions#tabline#get()
set tabstop=4
set termencoding=utf-8
set textwidth=80
set updatetime=100
set whichwrap=h,l
set wildignore=*.bak,*.o,*.e,*~
set wildmenu
set wildmode=list:longest,full
" vim: set ft=vim :
