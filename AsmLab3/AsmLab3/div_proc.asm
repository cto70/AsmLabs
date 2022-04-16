.686
.model flat, C 
.code 
PUBLIC div_proc
div_proc PROC
	push ebp
	mov ebp,esp
	finit
	mov eax, [ebp + 8]; 
	
	fld1
	fld qword ptr [eax]
	fprem
	fld qword ptr [eax]
	fsub st(0), st(1)
	fxch st(1)
	f2xm1
	fadd st(0), st(2)
	fscale 
    fxch
	fincstp
    fdivp st(1), st(0)
	
	mov eax, [ebp + 12];      
	fst qword ptr [eax];      
    pop ebp
	ret	
div_proc ENDP 
end