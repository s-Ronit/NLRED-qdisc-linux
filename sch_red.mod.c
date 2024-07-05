#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb43f9365, "ktime_get" },
	{ 0x9fb2ed72, "__qdisc_calculate_pkt_len" },
	{ 0xeb191a2b, "tcf_qevent_handle" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xb1419ec1, "noop_qdisc" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0x49455c8f, "qdisc_tree_reduce_backlog" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x246fdb7b, "qdisc_offload_graft_helper" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9f6f9a2e, "bfifo_qdisc_ops" },
	{ 0xf0ede64d, "fifo_create_dflt" },
	{ 0x90176e2b, "qdisc_hash_add" },
	{ 0xdc0e4855, "timer_delete" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xfa4d2f03, "__nla_parse" },
	{ 0x96b05ec8, "tcf_qevent_validate_change" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x74053ebb, "tcf_qevent_init" },
	{ 0x8d522714, "__rcu_read_lock" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa965ca81, "reciprocal_value" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0x2469810f, "__rcu_read_unlock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x122c3a7e, "_printk" },
	{ 0x8a08e37f, "register_qdisc" },
	{ 0x6ba3b631, "gnet_stats_copy_app" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xac3123c, "qdisc_reset" },
	{ 0x62f9d40c, "unregister_qdisc" },
	{ 0x47eb2263, "qdisc_offload_dump_helper" },
	{ 0xa55a43fb, "nla_put" },
	{ 0xad83b8cd, "tcf_qevent_dump" },
	{ 0x140ae464, "skb_trim" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe40d7565, "skb_copy_bits" },
	{ 0x3212cf97, "tcf_qevent_destroy" },
	{ 0x82ee90dc, "timer_delete_sync" },
	{ 0xe15a983f, "qdisc_put" },
	{ 0x9ffbb7a5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0ADFA502758FCFA92644571");
