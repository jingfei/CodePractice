;;; file: palindrome.lsp


(defun palindrome(n)
 (if ( equal n (reverse n) ) T NIL) ; n==n.reverse()?true:false
)

;; (print (palindrome '(a b c)))
;; (print (palindrome '(m a d a m)))
;; (print (palindrome '(cat dog)))
;; (print (palindrome '()))
;; (print (palindrome '(cat dog bird bird dog cat)))

