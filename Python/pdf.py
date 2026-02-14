# make_pdf.py
# pip install weasyprint
from weasyprint import HTML, CSS
from datetime import datetime
import pathlib

def build_html(content_html: str) -> str:
    now = datetime.now().strftime("%d %b %Y, %I:%M %p")
    css = """
    @page {
      size: A4;
      margin: 18mm 15mm 18mm 15mm;
      @top-center { content: "Data Structures Lab – Hinglish"; color: #64748b; font-size: 10px; }
      @bottom-center { content: "Page " counter(page) " of " counter(pages); color: #64748b; font-size: 10px; }
    }
    /* PDF Outline (bookmarks): control depth via bookmark-level */
    h1   { bookmark-level: 1 }
    h2   { bookmark-level: 2 }
    h3   { bookmark-level: 3 }

    :root {
      --accent: #1f6feb;
      --text: #0f172a;
      --muted: #475569;
      --code-bg: #0b1220;
      --code-fg: #e2e8f0;
      --kbd-bg: #f1f5f9;
      --rule: #e2e8f0;
    }
    body { font-family: system-ui, -apple-system, Segoe UI, Roboto, Arial, sans-serif; color: var(--text); line-height: 1.5; font-size: 12.5px; }
    h1, h2, h3 { color: var(--accent); page-break-after: avoid; margin: 0.2em 0 0.35em; }
    h1 { font-size: 26px; }
    h2 { font-size: 18px; border-bottom: 1px solid var(--rule); padding-bottom: 6px; }
    h3 { font-size: 14px; }

    .muted { color: var(--muted); }
    .small { color: var(--muted); font-size: 11px; }
    .box { border: 1px solid #e5e7eb; border-radius: 8px; padding: 10px 12px; background: #fafafa; margin: 10px 0; }

    /* Code & ASCII */
    pre, code, .code {
      font-family: "DejaVu Sans Mono", "Cascadia Mono", "JetBrains Mono", ui-monospace, Menlo, Consolas, monospace;
    }
    pre {
      background: var(--code-bg);
      color: var(--code-fg);
      padding: 10px 12px;
      border-radius: 6px;
      border: 1px solid #0f172a;
      white-space: pre-wrap;
      word-break: break-word;
      font-size: 11.5px;
      page-break-inside: avoid; /* keep code blocks intact */
    }
    code { background: #0f172a; color: #e2e8f0; padding: 1px 4px; border-radius: 4px; font-size: 11.5px; }
    ul { margin: 0.3em 0 0.6em 1.2em; }
    .toc li { margin: 2px 0; }
    .page-break { page-break-before: always; }
    .keep { page-break-inside: avoid; } /* keep diagrams/dry runs together */
    a { color: var(--accent); text-decoration: none; }
    """

    tpl = f"""
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>DSA Lab – Hinglish Explanations</title>
<style>{css}</style>
</head>
<body>

<section id="cover" style="text-align:center; margin-top: 12mm;">
  <h1>Data Structures Lab – Hinglish Explanations</h1>
  <p class="muted">Weeks 1–8 • Line-by-line code, dry runs, ASCII diagrams</p>
  <p class="small">Generated on {now}</p>
</section>

<div class="page-break"></div>

<section id="toc">
  <h2>Table of Contents</h2>
  <ol class="toc">
    <li><a href="#week1">Week 1 – Arrays</a></li>
    <li><a href="#week2">Week 2 – Matrices</a></li>
    <li><a href="#week3">Week 3 – Stacks (Array)</a></li>
    <li><a href="#week4">Week 4 – Strings & Two Stacks</a></li>
    <li><a href="#week5">Week 5 – Queues & Deque</a></li>
    <li><a href="#week6">Week 6 – Stack↔Queue</a></li>
    <li><a href="#week7">Week 7 – Linked Lists</a></li>
    <li><a href="#week8">Week 8 – Doubly Linked Lists</a></li>
  </ol>
</section>

<div class="page-break"></div>

{content_html}

<section class="page-break" id="appendix">
  <h2>Appendix</h2>
  <div class="box keep">
    <strong>Notes:</strong>
    <ul>
      <li>Complexities in Big-O; ASCII diagrams are monospace-dependent.</li>
      <li>Anchors enable clickable ToC and PDF bookmarks.</li>
      <li>Code blocks and diagrams avoid page breaks mid-block.</li>
    </ul>
  </div>
</section>

</body>
</html>
"""
    return tpl

def main():
    # Replace the sample content with full sections.
    content_html = r"""
<section id="week1">
  <h2>Week 1 — Left Rotate Array</h2>
  <h3>Purpose</h3>
  <p class="keep">Array ko <strong>k</strong> times left rotate karna: shuru ke k elements end me chale jaate hain.</p>

  <h3>Code (C)</h3>
  <pre>
void leftRotate(int arr[], int n, int k) {{
    k = k % n;
    int temp[k];
    for (int i = 0; i &lt; k; i++) temp[i] = arr[i];
    for (int i = 0; i &lt; n - k; i++) arr[i] = arr[i + k];
    for (int i = 0; i &lt; k; i++) arr[n - k + i] = temp[i];
}}
  </pre>

  <h3>Line-by-line (Hinglish)</h3>
  <ul class="keep">
    <li><code>k = k % n;</code> k ko range me laata hai.</li>
    <li><code>temp[k]</code> first k elements ke liye buffer.</li>
    <li><code>arr[i] = arr[i+k]</code> se left shift hota hai.</li>
    <li>End me <code>temp</code> ko array ke last me paste karte hain.</li>
  </ul>

  <h3>Dry Run</h3>
  <pre class="keep">
arr = [1 2 3 4 5], k=2
temp = [1 2]
Shift: [3 4 5 _ _]
Paste: [3 4 5 1 2]
  </pre>

  <h3>ASCII Diagram</h3>
  <pre class="keep">
Before: 1 2 3 4 5
Take:   [1 2] -> temp
Shift:  3 4 5 _ _
Place:  3 4 5 1 2
  </pre>
</section>

<div class="page-break"></div>

<section id="week2">
  <h2>Week 2 — Search in Row-Column Sorted Matrix</h2>
  <p class="keep">Top-right se start karke &gt; key to left, &lt; key to down; milte hi success.</p>
  <h3>Staircase Path</h3>
  <pre class="keep">
(start at top-right)
&gt; key : move left
&lt; key : move down
== key: found
  </pre>
</section>

<!-- Continue: #week3..#week8, each section with code, line-by-line, dry run, ASCII diagrams. -->
"""

    html = build_html(content_html)
    out = pathlib.Path("ds_explanations.pdf")
    HTML(string=html, base_url=str(pathlib.Path().resolve())).write_pdf(str(out))
    print(f"PDF generated: {out.resolve()}")

if __name__ == '__main__':
    # put your main code here

    main()