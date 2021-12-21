
ExternC:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 72 2f 00 00    	pushq  0x2f72(%rip)        # 3f98 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 73 2f 00 00 	bnd jmpq *0x2f73(%rip)        # 3fa0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 4d 2f 00 00 	bnd jmpq *0x2f4d(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001080 <__cxa_atexit@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 1d 2f 00 00 	bnd jmpq *0x2f1d(%rip)        # 3fa8 <__cxa_atexit@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <_ZNSolsEPFRSoS_E@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 15 2f 00 00 	bnd jmpq *0x2f15(%rip)        # 3fb0 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <_ZNSt8ios_base4InitC1Ev@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 0d 2f 00 00 	bnd jmpq *0x2f0d(%rip)        # 3fb8 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <_ZNSolsEi@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 05 2f 00 00 	bnd jmpq *0x2f05(%rip)        # 3fc0 <_ZNSolsEi@GLIBCXX_3.4>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	4c 8d 05 16 02 00 00 	lea    0x216(%rip),%r8        # 12f0 <__libc_csu_fini>
    10da:	48 8d 0d 9f 01 00 00 	lea    0x19f(%rip),%rcx        # 1280 <__libc_csu_init>
    10e1:	48 8d 3d d9 00 00 00 	lea    0xd9(%rip),%rdi        # 11c1 <main>
    10e8:	ff 15 f2 2e 00 00    	callq  *0x2ef2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ee:	f4                   	hlt    
    10ef:	90                   	nop

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4010 <__TMC_END__>
    10f7:	48 8d 05 12 2f 00 00 	lea    0x2f12(%rip),%rax        # 4010 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 ce 2e 00 00 	mov    0x2ece(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmpq   *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d e9 2e 00 00 	lea    0x2ee9(%rip),%rdi        # 4010 <__TMC_END__>
    1127:	48 8d 35 e2 2e 00 00 	lea    0x2ee2(%rip),%rsi        # 4010 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 a5 2e 00 00 	mov    0x2ea5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmpq   *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d e5 2f 00 00 00 	cmpb   $0x0,0x2fe5(%rip)        # 4150 <completed.8060>
    116b:	75 2b                	jne    1198 <__do_global_dtors_aux+0x38>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 52 2e 00 00 	cmpq   $0x0,0x2e52(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0c                	je     1187 <__do_global_dtors_aux+0x27>
    117b:	48 8b 3d 86 2e 00 00 	mov    0x2e86(%rip),%rdi        # 4008 <__dso_handle>
    1182:	e8 e9 fe ff ff       	callq  1070 <__cxa_finalize@plt>
    1187:	e8 64 ff ff ff       	callq  10f0 <deregister_tm_clones>
    118c:	c6 05 bd 2f 00 00 01 	movb   $0x1,0x2fbd(%rip)        # 4150 <completed.8060>
    1193:	5d                   	pop    %rbp
    1194:	c3                   	retq   
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	c3                   	retq   
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	e9 77 ff ff ff       	jmpq   1120 <register_tm_clones>

00000000000011a9 <func>:
    11a9:	f3 0f 1e fa          	endbr64 
    11ad:	55                   	push   %rbp
    11ae:	48 89 e5             	mov    %rsp,%rbp
    11b1:	89 7d fc             	mov    %edi,-0x4(%rbp)
    11b4:	89 75 f8             	mov    %esi,-0x8(%rbp)
    11b7:	8b 55 fc             	mov    -0x4(%rbp),%edx
    11ba:	8b 45 f8             	mov    -0x8(%rbp),%eax
    11bd:	01 d0                	add    %edx,%eax
    11bf:	5d                   	pop    %rbp
    11c0:	c3                   	retq   

00000000000011c1 <main>:
    11c1:	f3 0f 1e fa          	endbr64 
    11c5:	55                   	push   %rbp
    11c6:	48 89 e5             	mov    %rsp,%rbp
    11c9:	48 83 ec 10          	sub    $0x10,%rsp
    11cd:	be 05 00 00 00       	mov    $0x5,%esi
    11d2:	bf 02 00 00 00       	mov    $0x2,%edi
    11d7:	e8 cd ff ff ff       	callq  11a9 <func>
    11dc:	89 45 fc             	mov    %eax,-0x4(%rbp)
    11df:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11e2:	89 c6                	mov    %eax,%esi
    11e4:	48 8d 3d 55 2e 00 00 	lea    0x2e55(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    11eb:	e8 c0 fe ff ff       	callq  10b0 <_ZNSolsEi@plt>
    11f0:	48 89 c2             	mov    %rax,%rdx
    11f3:	48 8b 05 d6 2d 00 00 	mov    0x2dd6(%rip),%rax        # 3fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    11fa:	48 89 c6             	mov    %rax,%rsi
    11fd:	48 89 d7             	mov    %rdx,%rdi
    1200:	e8 8b fe ff ff       	callq  1090 <_ZNSolsEPFRSoS_E@plt>
    1205:	b8 00 00 00 00       	mov    $0x0,%eax
    120a:	c9                   	leaveq 
    120b:	c3                   	retq   

000000000000120c <_Z41__static_initialization_and_destruction_0ii>:
    120c:	f3 0f 1e fa          	endbr64 
    1210:	55                   	push   %rbp
    1211:	48 89 e5             	mov    %rsp,%rbp
    1214:	48 83 ec 10          	sub    $0x10,%rsp
    1218:	89 7d fc             	mov    %edi,-0x4(%rbp)
    121b:	89 75 f8             	mov    %esi,-0x8(%rbp)
    121e:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    1222:	75 32                	jne    1256 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    1224:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    122b:	75 29                	jne    1256 <_Z41__static_initialization_and_destruction_0ii+0x4a>
    122d:	48 8d 3d 1d 2f 00 00 	lea    0x2f1d(%rip),%rdi        # 4151 <_ZStL8__ioinit>
    1234:	e8 67 fe ff ff       	callq  10a0 <_ZNSt8ios_base4InitC1Ev@plt>
    1239:	48 8d 15 c8 2d 00 00 	lea    0x2dc8(%rip),%rdx        # 4008 <__dso_handle>
    1240:	48 8d 35 0a 2f 00 00 	lea    0x2f0a(%rip),%rsi        # 4151 <_ZStL8__ioinit>
    1247:	48 8b 05 aa 2d 00 00 	mov    0x2daa(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    124e:	48 89 c7             	mov    %rax,%rdi
    1251:	e8 2a fe ff ff       	callq  1080 <__cxa_atexit@plt>
    1256:	90                   	nop
    1257:	c9                   	leaveq 
    1258:	c3                   	retq   

0000000000001259 <_GLOBAL__sub_I_main>:
    1259:	f3 0f 1e fa          	endbr64 
    125d:	55                   	push   %rbp
    125e:	48 89 e5             	mov    %rsp,%rbp
    1261:	be ff ff 00 00       	mov    $0xffff,%esi
    1266:	bf 01 00 00 00       	mov    $0x1,%edi
    126b:	e8 9c ff ff ff       	callq  120c <_Z41__static_initialization_and_destruction_0ii>
    1270:	5d                   	pop    %rbp
    1271:	c3                   	retq   
    1272:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1279:	00 00 00 
    127c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001280 <__libc_csu_init>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	41 57                	push   %r15
    1286:	4c 8d 3d eb 2a 00 00 	lea    0x2aeb(%rip),%r15        # 3d78 <__frame_dummy_init_array_entry>
    128d:	41 56                	push   %r14
    128f:	49 89 d6             	mov    %rdx,%r14
    1292:	41 55                	push   %r13
    1294:	49 89 f5             	mov    %rsi,%r13
    1297:	41 54                	push   %r12
    1299:	41 89 fc             	mov    %edi,%r12d
    129c:	55                   	push   %rbp
    129d:	48 8d 2d e4 2a 00 00 	lea    0x2ae4(%rip),%rbp        # 3d88 <__do_global_dtors_aux_fini_array_entry>
    12a4:	53                   	push   %rbx
    12a5:	4c 29 fd             	sub    %r15,%rbp
    12a8:	48 83 ec 08          	sub    $0x8,%rsp
    12ac:	e8 4f fd ff ff       	callq  1000 <_init>
    12b1:	48 c1 fd 03          	sar    $0x3,%rbp
    12b5:	74 1f                	je     12d6 <__libc_csu_init+0x56>
    12b7:	31 db                	xor    %ebx,%ebx
    12b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12c0:	4c 89 f2             	mov    %r14,%rdx
    12c3:	4c 89 ee             	mov    %r13,%rsi
    12c6:	44 89 e7             	mov    %r12d,%edi
    12c9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    12cd:	48 83 c3 01          	add    $0x1,%rbx
    12d1:	48 39 dd             	cmp    %rbx,%rbp
    12d4:	75 ea                	jne    12c0 <__libc_csu_init+0x40>
    12d6:	48 83 c4 08          	add    $0x8,%rsp
    12da:	5b                   	pop    %rbx
    12db:	5d                   	pop    %rbp
    12dc:	41 5c                	pop    %r12
    12de:	41 5d                	pop    %r13
    12e0:	41 5e                	pop    %r14
    12e2:	41 5f                	pop    %r15
    12e4:	c3                   	retq   
    12e5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    12ec:	00 00 00 00 

00000000000012f0 <__libc_csu_fini>:
    12f0:	f3 0f 1e fa          	endbr64 
    12f4:	c3                   	retq   

Disassembly of section .fini:

00000000000012f8 <_fini>:
    12f8:	f3 0f 1e fa          	endbr64 
    12fc:	48 83 ec 08          	sub    $0x8,%rsp
    1300:	48 83 c4 08          	add    $0x8,%rsp
    1304:	c3                   	retq   
