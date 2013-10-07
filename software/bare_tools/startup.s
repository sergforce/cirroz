.text
.code 32

.global _start
.func _start


_start:
    ldr   sp,=0x80017000
    b main2
_end:
    b _end
