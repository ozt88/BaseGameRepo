
var res = {
	img: {}
};

function loadData() {
	var data = [
		"tile.png"
		];
	data.forEach(function(img_name){
		res.img[img_name] = new Image();
		res.img[img_name].src = "image/" + img_name;
	});
}


//----------------------------------------[Game]----------------------------------------

var canv, g;

var key = {
	state: [],
	now: [],
	old: [],
	update: function(){this.old = this.now.slice(0);this.now = this.state.slice(0);},
	isTriggered: function(key){return !this.old[key]&&this.now[key]},
	isPressed: function(key){return this.now[key];},
	isReleased: function(key){return this.old[key]&&!this.now[key];}
};

var mouse = {
	state: [],
	now: [],
	old: [],
	x: 0,
	y: 0,
	// keycode : left 0, right 2
	update: function(){this.old = this.now.slice(0);this.now = this.state.slice(0);},
	isTriggered: function(key){return !this.old[key]&&this.now[key]},
	isPressed: function(key){return this.now[key]},
	isReleased: function(key){return this.old[key]&&!this.now[key]}
};

function init() {
	canv = document.getElementById("canv");
	g = canv.getContext('2d');

	window.addEventListener('keydown', function(event) { key.state[event.keyCode] = true; });
	window.addEventListener('keyup', function(event) { key.state[event.keyCode] = false; });

	canv.addEventListener('mouseup', function(event) { mouse.state[event.button] = false; });
	canv.addEventListener('mousedown', function(event) { mouse.state[event.button] = true; });
	canv.addEventListener('mousemove', function(event) { mouse.x = event.layerX; mouse.y = event.layerY; });

	loadData();
	resetTile();

	setInterval(gameLoop, Math.round(1000/60));
}

function gameLoop() {
	g.clearRect(0,0,canv.width,canv.height);
	
	key.update();
	mouse.update();
	
	inputProc();
	update();
	draw();

/*
	g.fillStyle = "black";
	g.font = "12px Arial";
	g.fillText("("+mouse.x+", "+mouse.y+")", 10, 15);

	var a = getTileXY(mouse.x, mouse.y);
	g.fillStyle = "black";
	g.font = "12px Arial";
	g.textAlign = "left";
	g.fillText("("+a.x+", "+a.y+")", 10, 30);
*/
}

function inputProc() {
	if (mouse.isPressed(0)) {
		var coord = getTileXY(mouse.x, mouse.y);
		var id = getTileID(coord.x, coord.y);
		tiles[id] = 1;
	}
	else if (mouse.isPressed(2)) {
		var coord = getTileXY(mouse.x, mouse.y);
		var id = getTileID(coord.x, coord.y);
		tiles[id] = 0;
	}

	if (key.isTriggered('R'.charCodeAt(0))) {
		resetTile();
	}
	else if (key.isTriggered('S'.charCodeAt(0))) {
		saveStageData();
	}
}

function update() {
}

function draw() {
	drawTile();
	drawGrid();
}

function drawGrid() {
	g.beginPath();

	for (var x = 40; x < canv.width; x += 40) {
		g.moveTo(x, 0);
		g.lineTo(x, canv.height);
	}
	for (var y = 40; y < canv.height; y += 40) {
		g.moveTo(0, y);
		g.lineTo(canv.width, y);
	}

	g.strokeStyle = "black";
	g.globalAlpha = 0.5;
	g.stroke();
	g.globalAlpha = 1;
}

//----------------------------------------[Stage]----------------------------------------

function loadStageData(data) {
	tiles = data.tile.tiles;
}

function saveStageData() {
	var o = {
		tile: {
			width: tile_w,
			height: tile_h,
			tiles: tiles
		}
	};
	prompt("복사하시오", JSON.stringify(o));
}

//----------------------------------------[Tile]----------------------------------------

var tiles = [];
var tile_w = 480/40;
var tile_h = 640/40;
var tile_num = tile_w * tile_h;

function resetTile() {
	tiles = [];
	for (var i = 0; i < tile_num; ++i)
		tiles.push(0);
}

function drawTile() {
	var img = res.img["tile.png"];
	for (var i = 0; i < tile_num; ++i) {
		var x = i % tile_w;
		var y = Math.floor(i / tile_w);
		var sx = tiles[i] % tile_w;
		var sy = Math.floor(tiles[i] / tile_w);
		g.drawImage(img, sx*40, sy*40, 40, 40, x*40, y*40, 40, 40);

		g.fillStyle = "grey";
		g.font = "12px Arial";
		g.textBaseline = "top";
		g.fillText(tiles[i], 2 + x*40, y*40);
		g.textBaseline = "alphabetic";
	}
}

function getTileXY(mouse_x, mouse_y) {
	var x = mouse_x;
	var y = mouse_y;
	return {x: Math.floor(x/40), y: Math.floor(y/40)};
}

function getTileID(x, y) {
	return x + y*tile_w;
}

