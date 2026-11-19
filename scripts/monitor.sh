
#!/bin/bash

# AEROSYNC - ATC Monitoring Script

PROJECT_DIR="$HOME/AEROSYNC"
LOG_DIR="$PROJECT_DIR/logs"
REPORT_DIR="$PROJECT_DIR/reports"

mkdir -p "$LOG_DIR" "$REPORT_DIR"

LOG_FILE="$LOG_DIR/monitor.log"
REPORT_FILE="$REPORT_DIR/flight_report.txt"

echo "======================================"
echo "       AEROSYNC ATC MONITORING"
echo "======================================"

echo "Monitoring started at: $(date)" | tee -a "$LOG_FILE"

echo ""
echo "Checking project files..."

if [ ! -f "$PROJECT_DIR/aerosync" ]; then
    echo "Process Management executable not found."
    exit 1
fi

if [ ! -f "$PROJECT_DIR/aerosync_ipc" ]; then
    echo "IPC executable not found."
    exit 1
fi

if [ ! -f "$PROJECT_DIR/aerosync_signals" ]; then
    echo "Signal Handling executable not found."
    exit 1
fi

echo "All executable files are available."

echo ""
echo "Running Process Management Module..."

"$PROJECT_DIR/aerosync" 2>&1 | tee -a "$LOG_FILE"

echo ""
echo "Running IPC Module..."

"$PROJECT_DIR/aerosync_ipc" 2>&1 | tee -a "$LOG_FILE"

echo ""
echo "Running Signal Handling Module..."

"$PROJECT_DIR/aerosync_signals" 2>&1 | tee -a "$LOG_FILE"

echo ""
echo "Generating flight report..."

{
    echo "===== AEROSYNC FLIGHT REPORT ====="
    echo "Report generated: $(date)"
    echo ""
    echo "Aircraft monitored:"
    echo "1. AI101"
    echo "2. BA207"
    echo "3. SQ412"
    echo ""
    echo "Execution modules:"
    echo "Process Management - Executed"
    echo "IPC Communication - Executed"
    echo "Signal Handling - Executed"
    echo ""
    echo "Detailed execution logs: $LOG_FILE"
} > "$REPORT_FILE"

echo "Flight report generated successfully."
echo "Report location: $REPORT_FILE"

echo ""
echo "Monitoring completed."
echo "======================================"

echo "Monitoring completed at: $(date)" >> "$LOG_FILE"
