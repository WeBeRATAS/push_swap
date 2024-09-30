****************************
Solo funciona cuando instalas con sudo ruby
*******************************************
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG
