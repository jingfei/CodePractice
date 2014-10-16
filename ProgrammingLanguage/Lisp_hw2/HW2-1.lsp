;;; file: HW2-1.lsp

(defun check(n i)  ;check prime form sqrt(n)
 (cond 
  ( (< i 2) T ) ; if(i<2) return true
  ( (= (mod n i) 0) NIL )  ; else if(n%i==0) return false
  ( t ( check n (- i 1) ) ) ; else return check(n,i)
 )
)

(defun prime(n)
 (check n (floor (sqrt n) ) ) ; check(n,(int)sqrt(n))
)
 
;; (print (prime 2))
;; (print (prime 239))
;; (print (prime 999))
;; (print (prime 17))
