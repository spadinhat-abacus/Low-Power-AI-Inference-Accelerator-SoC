//============================================================
// ccnuma_pkg.sv
// Common types, enums, parameters for ccNUMA fabric
//============================================================

package ccnuma_pkg;

  // -------------------------------
  // Basic parameters
  // -------------------------------
  parameter int CCNUMA_ADDR_WIDTH   = 48;
  parameter int CCNUMA_DATA_WIDTH   = 64;
  parameter int CCNUMA_BYTEEN_WIDTH = CCNUMA_DATA_WIDTH/8;
  parameter int CCNUMA_TXNID_WIDTH  = 12;
  parameter int CCNUMA_NODEID_WIDTH = 8;   // up to 256 agents

  // Special dst ID for broadcast / snoop
  localparam logic [CCNUMA_NODEID_WIDTH-1:0] CCNUMA_DST_BCAST = {CCNUMA_NODEID_WIDTH{1'b1}};

  // -------------------------------
  // Packet types
  // -------------------------------
  typedef enum logic [3:0] {
    PKT_READ_REQ,     // load miss or read
    PKT_READ_RESP,    // read data returned
    PKT_WRITE_REQ,    // store / write
    PKT_WRITE_ACK,    // write completion
    PKT_INV_REQ,      // invalidate snoop
    PKT_INV_ACK,      // invalidate ack
    PKT_SNOOP_REQ,    // generic snoop
    PKT_SNOOP_RESP,   // snoop response
    PKT_ATOM_REQ,     // atomics / RMW
    PKT_ATOM_RESP     // atomic response
  } pkt_type_e;

  // -------------------------------
  // MESI states (local caches)
  // -------------------------------
  typedef enum logic [2:0] {
    MESI_I,
    MESI_S,
    MESI_E,
    MESI_M,
    MESI_TRANS   // transient / in-flight
  } mesi_e;

  // -------------------------------
  // Fabric packet struct
  // -------------------------------
  typedef struct packed {
    pkt_type_e                                  type;
    logic [CCNUMA_TXNID_WIDTH-1:0]              txn_id;
    logic [CCNUMA_NODEID_WIDTH-1:0]             src;
    logic [CCNUMA_NODEID_WIDTH-1:0]             dst;      // CCNUMA_DST_BCAST = broadcast
    logic [CCNUMA_ADDR_WIDTH-1:0]               addr;
    logic [CCNUMA_DATA_WIDTH-1:0]               data;
    logic [CCNUMA_BYTEEN_WIDTH-1:0]             byte_en;
    logic [1:0]                                 resp_code; // OK / ERR / RETRY etc.
    logic [2:0]                                 mesi_hint; // optional MESI hint
  } packet_t;

endpackage : ccnuma_pkg

