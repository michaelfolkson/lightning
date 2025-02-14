#include "../onchaind.c"
#include "../onchaind_wiregen.c"
#include "../onchaind_wire.c"
#include "../../hsmd/hsmd_wiregen.c"
#include <ccan/str/hex/hex.h>
#include <common/dev_disconnect.h>
#include <common/onionreply.h>
#include <common/version.h>
#include <err.h>
#include <zlib.h>

volatile bool logging_io;
struct backtrace_state *backtrace_state;

/* AUTOGENERATED MOCKS START */
/* Generated stub for dup_onionreply */
struct onionreply *dup_onionreply(const tal_t *ctx UNNEEDED,
				  const struct onionreply *r TAKES UNNEEDED)
{ fprintf(stderr, "dup_onionreply called!\n"); abort(); }
/* Generated stub for fromwire_bip32_key_version */
void fromwire_bip32_key_version(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
				struct bip32_key_version *version UNNEEDED)
{ fprintf(stderr, "fromwire_bip32_key_version called!\n"); abort(); }
/* Generated stub for fromwire_chain_coin_mvt */
void fromwire_chain_coin_mvt(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct chain_coin_mvt *mvt UNNEEDED)
{ fprintf(stderr, "fromwire_chain_coin_mvt called!\n"); abort(); }
/* Generated stub for fromwire_ext_key */
void fromwire_ext_key(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct ext_key *bip32 UNNEEDED)
{ fprintf(stderr, "fromwire_ext_key called!\n"); abort(); }
/* Generated stub for fromwire_node_id */
void fromwire_node_id(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct node_id *id UNNEEDED)
{ fprintf(stderr, "fromwire_node_id called!\n"); abort(); }
/* Generated stub for fromwire_onionreply */
struct onionreply *fromwire_onionreply(const tal_t *ctx UNNEEDED,
				       const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_onionreply called!\n"); abort(); }
/* Generated stub for fromwire_utxo */
struct utxo *fromwire_utxo(const tal_t *ctx UNNEEDED, const u8 **ptr UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_utxo called!\n"); abort(); }
/* Generated stub for master_badmsg */
void master_badmsg(u32 type_expected UNNEEDED, const u8 *msg)
{ fprintf(stderr, "master_badmsg called!\n"); abort(); }
/* Generated stub for memleak_find_allocations */
struct htable *memleak_find_allocations(const tal_t *ctx UNNEEDED,
					const void *exclude1 UNNEEDED,
					const void *exclude2 UNNEEDED)
{ fprintf(stderr, "memleak_find_allocations called!\n"); abort(); }
/* Generated stub for new_coin_penalty_sat */
struct chain_coin_mvt *new_coin_penalty_sat(const tal_t *ctx UNNEEDED,
					    const char *account_name UNNEEDED,
					    const struct bitcoin_txid *txid UNNEEDED,
					    const struct bitcoin_txid *out_txid UNNEEDED,
					    u32 vout UNNEEDED,
					    u32 blockheight UNNEEDED,
					    struct amount_sat amount UNNEEDED)
{ fprintf(stderr, "new_coin_penalty_sat called!\n"); abort(); }
/* Generated stub for new_coin_withdrawal */
struct chain_coin_mvt *new_coin_withdrawal(const tal_t *ctx UNNEEDED,
					  const char *account_name UNNEEDED,
					  const struct bitcoin_txid *tx_txid UNNEEDED,
					  const struct bitcoin_txid *out_txid UNNEEDED,
					  u32 vout UNNEEDED,
					  u32 blockheight UNNEEDED,
					  struct amount_msat amount UNNEEDED)
{ fprintf(stderr, "new_coin_withdrawal called!\n"); abort(); }
/* Generated stub for status_failed */
void status_failed(enum status_failreason code UNNEEDED,
		   const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "status_failed called!\n"); abort(); }
/* Generated stub for status_vfmt */
void status_vfmt(enum log_level level UNNEEDED,
		 const struct node_id *peer UNNEEDED,
		 const char *fmt UNNEEDED, va_list ap UNNEEDED)
{ fprintf(stderr, "status_vfmt called!\n"); abort(); }
/* Generated stub for towire_bip32_key_version */
void towire_bip32_key_version(u8 **cursor UNNEEDED, const struct bip32_key_version *version UNNEEDED)
{ fprintf(stderr, "towire_bip32_key_version called!\n"); abort(); }
/* Generated stub for towire_ext_key */
void towire_ext_key(u8 **pptr UNNEEDED, const struct ext_key *bip32 UNNEEDED)
{ fprintf(stderr, "towire_ext_key called!\n"); abort(); }
/* Generated stub for towire_node_id */
void towire_node_id(u8 **pptr UNNEEDED, const struct node_id *id UNNEEDED)
{ fprintf(stderr, "towire_node_id called!\n"); abort(); }
/* Generated stub for towire_onionreply */
void towire_onionreply(u8 **cursor UNNEEDED, const struct onionreply *r UNNEEDED)
{ fprintf(stderr, "towire_onionreply called!\n"); abort(); }
/* Generated stub for towire_utxo */
void towire_utxo(u8 **pptr UNNEEDED, const struct utxo *utxo UNNEEDED)
{ fprintf(stderr, "towire_utxo called!\n"); abort(); }
/* Generated stub for version */
const char *version(void)
{ fprintf(stderr, "version called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

#if DEVELOPER
/* Generated stub for dev_disconnect_init */
void dev_disconnect_init(int fd UNNEEDED)
{ fprintf(stderr, "dev_disconnect_init called!\n"); abort(); }
/* Generated stub for dump_memleak */
bool dump_memleak(struct htable *memtable UNNEEDED,
		  void  (*print)(const char *fmt UNNEEDED, ...))
{ fprintf(stderr, "dump_memleak called!\n"); abort(); }
/* Generated stub for memleak_init */
void memleak_init(void)
{ fprintf(stderr, "memleak_init called!\n"); abort(); }
/* Generated stub for memleak_remove_region */
void memleak_remove_region(struct htable *memtable UNNEEDED,
			   const void *p UNNEEDED, size_t bytelen UNNEEDED)
{ fprintf(stderr, "memleak_remove_region called!\n"); abort(); }
/* Generated stub for memleak_status_broken */
void memleak_status_broken(const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "memleak_status_broken called!\n"); abort(); }
#endif

/* Noops */
void status_setup_sync(int fd UNNEEDED)
{
}
void status_fmt(enum log_level level,
		const struct node_id *peer,
		const char *fmt, ...)
{
}
void *notleak_(const void *ptr UNNEEDED, bool plus_children UNNEEDED)
{
	return (void *)ptr;
}
void peer_billboard(bool perm UNNEEDED, const char *fmt UNNEEDED, ...)
{
}
struct chain_coin_mvt *new_coin_chain_fees(const tal_t *ctx UNNEEDED,
					   const char *account_name UNNEEDED,
					   const struct bitcoin_txid *tx_txid UNNEEDED,
					   u32 blockheight UNNEEDED,
					   struct amount_msat amount UNNEEDED)
{
	return NULL;
}

/* Generated stub for new_coin_chain_fees_sat */
struct chain_coin_mvt *new_coin_chain_fees_sat(const tal_t *ctx UNNEEDED,
					       const char *account_name UNNEEDED,
					       const struct bitcoin_txid *tx_txid UNNEEDED,
					       u32 blockheight UNNEEDED,
					       struct amount_sat amount UNNEEDED)
{
	return NULL;
}
/* Generated stub for new_coin_journal_entry */
struct chain_coin_mvt *new_coin_journal_entry(const tal_t *ctx UNNEEDED,
					      const char *account_name UNNEEDED,
					      const struct bitcoin_txid *txid UNNEEDED,
					      const struct bitcoin_txid *out_txid UNNEEDED,
					      u32 vout UNNEEDED,
					      u32 blockheight UNNEEDED,
					      struct amount_msat amount UNNEEDED,
					      bool is_credit UNNEEDED)
{
	return NULL;
}
struct chain_coin_mvt *new_coin_onchain_htlc_sat(const tal_t *ctx UNNEEDED,
						 const char *account_name UNNEEDED,
						 const struct bitcoin_txid *txid UNNEEDED,
						 const struct bitcoin_txid *out_txid UNNEEDED,
						 u32 vout UNNEEDED,
						 struct sha256 payment_hash UNNEEDED,
						 u32 blockheight UNNEEDED,
						 struct amount_sat amount UNNEEDED,
						 bool is_credit UNNEEDED)
{
	return NULL;
}
struct chain_coin_mvt *new_coin_withdrawal_sat(const tal_t *ctx UNNEEDED,
					       const char *account_name UNNEEDED,
					       const struct bitcoin_txid *tx_txid UNNEEDED,
					       const struct bitcoin_txid *out_txid UNNEEDED,
					       u32 vout UNNEEDED,
					       u32 blockheight UNNEEDED,
					       struct amount_sat amount UNNEEDED)
{
	return NULL;
}
void towire_chain_coin_mvt(u8 **pptr UNNEEDED, const struct chain_coin_mvt *mvt UNNEEDED)
{
}

bool wire_sync_write(int fd, const void *msg TAKES)
{
	if (taken(msg))
		tal_free(msg);
	return true;
}

u8 *wire_sync_read(const tal_t *ctx, int fd)
{
	char line[5000];
	u8 *ret;
	static gzFile stream;
	size_t hexlen;

	/* Don't run this under valgrind in CI: takes too long! */
	if (getenv("VALGRIND") && streq(getenv("VALGRIND"), "1"))
		goto exit;

	if (!stream) {
		stream = gzopen("onchaind/test/onchainstress-data.gz", "rb");
		if (!stream)
			err(1, "opening onchaind/test/onchainstress-data.gz");
	}

	do {
		if (!gzgets(stream, line, sizeof(line)))
			goto exit;
	} while (!strstarts(line, "read "));

	/* Ignore prefix and \n at end */
	hexlen = strlen(line) - strlen("read ") - 1;
	ret = tal_arr(ctx, u8, hex_data_size(hexlen));
	if (!hex_decode(line + strlen("read "), hexlen, ret, tal_bytelen(ret)))
		errx(1, "Bad hex string '%s'", line);
	return ret;

exit:
	daemon_shutdown();
	/* Free top-level ctx pointer! */
	while (tal_first(NULL))
		tal_free(tal_first(NULL));
	exit(0);
}
