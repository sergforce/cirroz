.text
.code 32

.global _start
.func _start


_start:
    ldr   sp,=0x8001FFF0
    b main2
_end:
    b _end
