# 
# 
#                             Online GCC Assembler.
#                 Code, Compile, Run and Debug assembly program online.
# Write your code in this editor and press "Run" button to execute it.
# 
# 


.data
.text
.global main
main:
    # set ecx to the hexadecimal value of the number
    # input: 3.5
     mov $0x40600000, %ecx
    # input: 1.1
    # mov $0x3f8ccccd, %ecx
    # input: 1.5
    # mov $0x3fc00000, %ecx

    mov $0x007FFFFF, %edx
    and %ecx, %edx
    
    mov $0x00400000, %eax
    and %edx, %eax
    cmp $0, %eax
    je mantissa_less
    
    mov $0x003FFFFF, %eax
    and %edx, %eax
    cmp $0, %eax
    je  mantissa_less
    
    mov $1, %eax
    jmp end
mantissa_less:
    mov $0, %eax
end:
    ret